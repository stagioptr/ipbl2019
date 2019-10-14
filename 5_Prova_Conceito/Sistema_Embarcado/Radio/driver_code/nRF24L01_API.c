/** @file API.c
 *
 * @author Runar Kjellhaug
 *
 * @compiler This program has been tested with Keil C51 V7.50.
 *
 *
 * $Date: 20.02.06 14:16 $
 * $Revision: 21 $
 *
 */
//#include <cygnal\c8051F320.h>
#include "nRF24L01_API_port.h"
#include "nRF24L01_API.h"
//#include "include\LL_API.h"

//**********************************************************//

//**********************************************************//

// Declare HW/SW SPI Mode variable
extern uint8_t SPI_Mode;

// Variable that indicates nRF24L01 interrupt source
extern uint8_t IRQ_Source;

uint8_t SPI_ID = 0;

//********************************************************************************************************************//

//**********************************************************//
//
//  Function: SPI_RW
//
//  Description:
//  Writes one byte to nRF24L01, and return the byte read
//  from nRF24L01 during write, according to SPI protocol
//
//  In/Out parameters:
//  In: 'byte', current byte to be written
//  Out: 'SPI0DAT', HW SPI mode, 'byte' SW SPI mode,
//
//  Author: RSK   Date: 28.11.05
//**********************************************************//
uint8_t SPI_RW(uint8_t byte) {
	const uint8_t sendByte = 0;
	uint8_t temp = 0;

	SPI_DRV_MasterTransferBlocking(SPI_ID, &Radio_MasterConfig0, &sendByte, &temp,
			1, 20);

	return temp;
}

//**********************************************************//
//
//  Function: SPI_Read
//
//  Description:
//  Read one byte from nRF24L01 register, 'reg'
//
//
//  In/Out parameters:
//  In: reg, register to read
//  Out: return reg_val, register value.
//
//
//  Author: RSK   Date: 28.11.05
//**********************************************************//
uint8_t SPI_Read(uint8_t reg) {
	uint8_t reg_val;

	GPIO_DRV_WritePinOutput(J2_6, 0);

	SPI_RW(reg);                                 // Select register to read from..
	reg_val = SPI_RW(0);                            // ..then read registervalue

	GPIO_DRV_WritePinOutput(J2_6, 1);

	return (reg_val);                                // return register value
}

//**********************************************************//
//
//  Function: SPI_RW_Reg
//
//  Description:
//  Writes value 'value' to register 'reg'
//
//
//  In/Out parameters:
//  In: 'reg' register to write value 'value' to.
//  Return status byte.
//
//  Author: RSK   Date: 28.11.05
//**********************************************************//
uint8_t SPI_RW_Reg(uint8_t reg, uint8_t value) {
	uint8_t status;

	GPIO_DRV_WritePinOutput(J2_6, 0);

	status = SPI_RW(reg);                           // select register
	SPI_RW(value);                                  // ..and write value to it..
	GPIO_DRV_WritePinOutput(J2_6, 1);

	return (status);                                // return nRF24L01 status byte
}

//**********************************************************//
//
//  Function: SPI_Write_Buf
//
//  Description:
//  Writes contents of buffer '*pBuf' to nRF24L01
//  Typically used to write TX payload, Rx/Tx address
//
//
//  In/Out parameters:
//  In: register 'reg' to write, buffer '*pBuf*' contains
//  data to be written and buffer size 'buf_size' is #of
//  bytes to be written
//  Out: return nRF24L01 status byte.
//
//  Author: RSK   Date: 28.11.05
//**********************************************************//
uint8_t SPI_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t bytes) {
	uint8_t status, byte_ctr;

	GPIO_DRV_WritePinOutput(J2_6, 0);
	status = SPI_RW(reg);      // Select register to write to and read status byte

	for (byte_ctr = 0; byte_ctr < bytes; byte_ctr++) // then write all byte in buffer(*pBuf)
		SPI_RW(*pBuf++);

	GPIO_DRV_WritePinOutput(J2_6, 1);

	return (status);                                // return nRF24L01 status byte
}

//**********************************************************//
//
//  Function: SPI_Read_Buf
//
//  Description:
//  Reads 'bytes' #of bytes from register 'reg'
//  Typically used to read RX payload, Rx/Tx address
//
//
//  In/Out parameters:
//  In: 'reg', register to read from, '*pBuf' are buffer
//  the read bytes are stored to and 'bytes' are #of bytes
//  to read.
//  Out: return nRF24L01 status byte.
//
//  Author: RSK   Date: 28.11.05
//**********************************************************//
uint8_t SPI_Read_Buf(uint8_t reg, uint8_t *pBuf, uint8_t bytes) {
	uint8_t status, byte_ctr;

	GPIO_DRV_WritePinOutput(J2_6, 0);
	status = SPI_RW(reg);      // Select register to write to and read status byte

	for (byte_ctr = 0; byte_ctr < bytes; byte_ctr++)
		pBuf[byte_ctr] = SPI_RW(0);     // Perform SPI_RW to read byte from nRF24L01

	GPIO_DRV_WritePinOutput(J2_6, 1);

	return (status);                                // return nRF24L01 status byte
}

//**********************************************************
//
//  nRF24L01 Program example
//
//  Description:
//  This example code is contains two functions,
//  'TX_Mode': program nRF24L01 to function as a PRIM:TX,
//  i.e. program TX_Address, RX_Address for auto ack,
//  TX Payload, setup of 'Auto Retransmit Delay' &
//  'Auto Retransmit Count', select RF channel,
//  Datarate & RF output power.
//
//  'RX_Mode': program nRF24L01 to function as a PRIM:RX,
//  i.e. ready to receive the packet that was sent with
//  the 'TX_Mode' function.
//
//
//  Author: RSK   Date: 28.11.05
//**********************************************************
#define TX_ADR_LENGTH   5                         // 5 uint8_ts TX(RX) address width
#define TX_PLOAD_WIDTH  16                        // 16 uint8_ts TX payload

// Predefine a static TX address
uint8_t TX_ADDRESS[TX_ADR_LENGTH] = { 0x34, 0x43, 0x10, 0x10, 0x01 };
// Predefine TX payload packet..
uint8_t TX_PAYLOAD[TX_PLOAD_WIDTH] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
		0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

extern uint8_t SPI_Buffer[32]; // Buffer to hold data from 'SPI_Read_Buf()' function

//**********************************************************
//
//  Function: TX_Mode
//
//  Description:
//  This function initializes one nRF24L01 device to
//  TX mode, set TX address, set RX address for auto.ack,
//  fill TX payload, select RF channel, datarate & TX pwr.
//  PWR_UP is set, CRC(2 uint8_ts) is enabled, & PRIM:TX.
//
//  ToDo: One high pulse(>10탎) on CE will now send this
//  packet and expext an acknowledgment from the RX device.
//
//
//  Author: RSK   Date: 28.11.05
//**********************************************************
void TX_Mode(void) {
	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_LENGTH); // Writes TX_Address to nRF24L01
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_LENGTH); // RX_Addr0 same as TX_Adr for Auto.Ack
	SPI_Write_Buf(WR_TX_PLOAD, TX_PAYLOAD, TX_PLOAD_WIDTH); // Writes data to TX payload

	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);            // Enable Auto.Ack:Pipe0
	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);        // Enable Pipe0
	SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x1a);       // 500탎 + 86탎, 10 retrans...
	SPI_RW_Reg(WRITE_REG + RF_CH, 40);              // Select RF channel 40
	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x0f); // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e); // Set PWR_UP bit, enable CRC(2 uint8_ts) & Prim:TX. MAX_RT & TX_DS enabled..

	GPIO_DRV_WritePinOutput(J1_8, 0); // Set CE pin high to enable RX device
	GPIO_DRV_WritePinOutput(J1_8, 1); // Set CE pin high to enable RX device

	//  This device is now ready to transmit one packet of 16 uint8_ts payload to a RX device at address
	//  '3443101001', with auto acknowledgment, retransmit count of 10(retransmit delay of 500탎+86탎)
	//  RF channel 40, datarate = 2Mbps with TX power = 0dBm.
}

//**********************************************************
//
//  Function: RX_Mode
//
//  Description:
//  This function initializes one nRF24L01 device to
//  RX Mode, set RX address, writes RX payload width,
//  select RF channel, datarate & LNA HCURR.
//  After init, CE is toggled high, which means that
//  this device is now ready to receive a datapacket.
//
//  Author: RSK   Date: 28.11.05
//**********************************************************
void RX_Mode(void) {
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_LENGTH); // Use the same address on the RX device as the TX device

	SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);            // Enable Auto.Ack:Pipe0
	SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);        // Enable Pipe0
	SPI_RW_Reg(WRITE_REG + RF_CH, 40);              // Select RF channel 40
	SPI_RW_Reg(WRITE_REG + RX_PW_P0, TX_PLOAD_WIDTH); // Select same RX payload width as TX Payload width
	SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x0f); // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR
	SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f); // Set PWR_UP bit, enable CRC(2 uint8_ts) & Prim:RX. RX_DR enabled..

	GPIO_DRV_WritePinOutput(J1_8, 1); // Set CE pin high to enable RX device

	//  This device is now ready to receive one packet of 16 uint8_ts payload from a TX device sending to address
	//  '3443101001', with auto acknowledgment, retransmit count of 10, RF channel 40 and datarate = 2Mbps.

}

/*
 void nRF24L01_IRQ(void)
 interrupt EXT_INT0
 {
 uint8_t temp,rx_pw;

 EA = 0; // disable global interrupt during processing
 temp = SPI_RW_Reg(WRITE_REG + STATUS, 0x70);// Read STATUS uint8_t and clear IRQ flag's(nRF24L01)

 if(temp & MAX_RT) IRQ_Source = MAX_RT;// Indicates max #of retransmit interrupt
 if(temp & TX_DS) IRQ_Source = TX_DS;// Indicates TX data succsessfully sent

 if(temp & RX_DR)// In RX mode, check for data received
 {
 // Data received, so find out which datapipe the data was received on:
 temp = (0x07 & (temp > 1));// Shift bits in status uint8_t one bit to LSB and mask 'Data Pipe Number'
 rx_pw = SPI_Read(READ_REG + RX_PW_P0 + temp);// Read current RX_PW_Pn register, where Pn is the pipe the data was received on..
 SPI_Read_Buf(RD_RX_PLOAD, SPI_Buffer, rx_pw);// Data from RX Payload register is now copied to SPI_Buffer[].

 IRQ_Source = RX_DR;// Indicates RX data received
 }
 EA = 1; // enable global interrupt again
 } */

