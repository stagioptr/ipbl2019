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
extern uint8_t nRF24L01_Mode;

// Variable that indicates nRF24L01 interrupt source
extern uint8_t IRQ_Source;

//**********************************************************//
//
//  Function: nRF24L01_RW
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
uint8_t nRF24L01_RW(uint8_t byte) {
	uint8_t sendByte = byte;
	uint8_t temp = 0;

	nRF24L01_SPI_TransferBlocking(&sendByte, &temp, 1);

	return temp;
}

//**********************************************************//
//
//  Function: nRF24L01_Read
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
uint8_t nRF24L01_Read(uint8_t reg) {
	uint8_t reg_val;

	nRF24L01_writeChpSelectPin(0);

	nRF24L01_RW(reg);                            // Select register to read from..
	reg_val = nRF24L01_RW(0);                         // ..then read registervalue

	nRF24L01_writeChpSelectPin(1);

	return (reg_val);                                // return register value
}

//**********************************************************//
//
//  Function: nRF24L01_writeRegister
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
uint8_t nRF24L01_writeRegister(uint8_t registerAddress, uint8_t value) {
	uint8_t status;

	nRF24L01_writeChpSelectPin(0);

	status = nRF24L01_RW( NRF24L01_WRITE_REG + registerAddress );                           // select register
	nRF24L01_RW(value);                               // ..and write value to it..
	nRF24L01_writeChpSelectPin(1);

	return (status);                                // return nRF24L01 status byte
}

//**********************************************************//
//
//  Function: nRF24L01_Write_Buf
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
uint8_t nRF24L01_Write_Buf(uint8_t reg, uint8_t *pBuf, uint8_t bytes) {
	uint8_t status, byte_ctr;

	nRF24L01_writeChpSelectPin(0);
	status = nRF24L01_RW(reg); // Select register to write to and read status byte

	for (byte_ctr = 0; byte_ctr < bytes; byte_ctr++) // then write all byte in buffer(*pBuf)
		nRF24L01_RW(*pBuf++);

	nRF24L01_writeChpSelectPin(1);

	return (status);                                // return nRF24L01 status byte
}

//**********************************************************//
//
//  Function: nRF24L01_Read_Buf
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
uint8_t nRF24L01_Read_Buf(uint8_t reg, uint8_t *pBuf, uint8_t bytes) {
	uint8_t status, byte_ctr;

	nRF24L01_writeChpSelectPin(0);
	status = nRF24L01_RW(reg); // Select register to write to and read status byte

	for (byte_ctr = 0; byte_ctr < bytes; byte_ctr++)
		pBuf[byte_ctr] = nRF24L01_RW(0); // Perform nRF24L01_RW to read byte from nRF24L01

	nRF24L01_writeChpSelectPin(1);

	return (status);                                // return nRF24L01 status byte
}

//********************************************************************************************************************//

NRF24L01_state_t nRF24L01_Init(void) {
	if ( !nRF24L01_SPI_Init_port() )
		return NRF24L01_STATE_FAIL_INIT;

	nRF24L01_writeRegister(NRF24L01_CONFIG, 0x00); // Disable device

	nRF24L01_writeRegister(NRF24L01_EN_AA, 0x01);            // Enable Auto.Ack:Pipe0
	nRF24L01_writeRegister(NRF24L01_EN_RXADDR, 0x01);        // Enable pipe 0.
	nRF24L01_writeRegister(NRF24L01_SETUP_RETR, 0x1a);  // 500�s + 86�s, 10 retrans...
	nRF24L01_writeRegister(NRF24L01_RF_CH, 40);              // Select RF channel 40
	nRF24L01_writeRegister(NRF24L01_RF_SETUP, 0x0f); // TX_PWR:0dBm, Datarate:2Mbps, LNA:HCURR

	nRF24L01_writeRegister(NRF24L01_FLUSH_RX, 0);
	nRF24L01_writeRegister(NRF24L01_FLUSH_TX, 0);
	nRF24L01_writeRegister(NRF24L01_STATUS, 0x70);			// Clear all interrupts

	if( !nRF24L01_EXTI_Init_port() )
		return NRF24L01_STATE_FAIL_INIT;

	return NRF24L01_STATE_SUCCESS;
}

NRF24L01_state_t nRF24L01_Denit(void) {
	nRF24L01_writeRegister(NRF24L01_CONFIG, 0x00);

	nRF24L01_writeRegister(NRF24L01_FLUSH_RX, 0);
	nRF24L01_writeRegister(NRF24L01_FLUSH_TX, 0);
	nRF24L01_writeRegister(NRF24L01_STATUS, 0x70);

	nRF24L01_writeRegister(NRF24L01_EN_AA, 0x00);
	nRF24L01_writeRegister(NRF24L01_EN_RXADDR, 0x00);
	nRF24L01_writeRegister(NRF24L01_SETUP_RETR, 0x00);
	nRF24L01_writeRegister(NRF24L01_RF_CH, 0);
	nRF24L01_writeRegister(NRF24L01_RF_SETUP, 0x00);

	if ( !nRF24L01_SPI_Deinit_port() )
		return NRF24L01_STATE_FAIL_DEINIT;

	if( !nRF24L01_EXTI_Deinit_port() )
		return NRF24L01_STATE_FAIL_DEINIT;

	return NRF24L01_STATE_SUCCESS;
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
//uint8_t TX_ADDRESS[TX_ADR_LENGTH] = { 0x34, 0x43, 0x10, 0x10, 0x01 };
// Predefine TX payload packet..
//uint8_t TX_PAYLOAD[TX_PLOAD_WIDTH] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
//		0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

//extern uint8_t nRF24L01_Buffer[32]; // Buffer to hold data from 'nRF24L01_Read_Buf()' function

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
//  ToDo: One high pulse(>10�s) on CE will now send this
//  packet and expext an acknowledgment from the RX device.
//
//
//  Author: RSK   Date: 28.11.05
//**********************************************************
NRF24L01_state_t nRF24L01_transmitPayload( NRF24L01_transferSetupStruct_t* setup ) {
	if( setup->payloadWidth > 32 || setup->payload == 0 || setup->addressLength > 5 )
		return NRF24L01_STATE_FAIL_INVALID_INPUT;

	nRF24L01_Write_Buf(NRF24L01_WRITE_REG + NRF24L01_TX_ADDR, setup->address, setup->addressLength); // Writes TX_Address to nRF24L01
	nRF24L01_Write_Buf(NRF24L01_WR_TX_PLOAD, setup->payload, setup->payloadWidth); // Writes data to TX payload

	nRF24L01_Write_Buf(NRF24L01_WRITE_REG + NRF24L01_RX_ADDR_P0, setup->address, setup->addressLength); // RX_Addr0 same as TX_Adr for Auto.Ack
	nRF24L01_writeRegister(NRF24L01_RX_PW_P0, setup->payloadWidth); // Select same RX payload width as TX Payload width

	nRF24L01_writeRegister(NRF24L01_CONFIG, 0x0e); // Set PWR_UP bit, enable CRC(2 uint8_ts) & Prim:TX. MAX_RT & TX_DS enabled..

	for (uint32_t tempo = 0; tempo < 1600; tempo++);

	nRF24L01_writeCEPin(0); // Set CE pin low to enable TX device
	for (uint32_t tempo = 0; tempo < 160; tempo++);

	nRF24L01_writeCEPin(1); // Set CE pin high to enable RX device

	//  This device is now ready to transmit one packet of 16 uint8_ts payload to a RX device at address
	//  '3443101001', with auto acknowledgment, retransmit count of 10(retransmit delay of 500�s+86�s)
	//  RF channel 40, datarate = 2Mbps with TX power = 0dBm.

	return NRF24L01_STATE_SUCCESS;
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
NRF24L01_state_t nRF24L01_receivePayload( NRF24L01_transferSetupStruct_t* setup ) {
	if( setup->payloadWidth > 32 || setup->payload == 0 || setup->addressLength > 5 )
		return NRF24L01_STATE_FAIL_INVALID_INPUT;

	nRF24L01_Write_Buf(NRF24L01_WRITE_REG + NRF24L01_RX_ADDR_P0, setup->address, setup->addressLength); // Use the same address on the RX device as the TX device
	nRF24L01_writeRegister(NRF24L01_RX_PW_P0, setup->payloadWidth); // Select same RX payload width as TX Payload width
	nRF24L01_writeRegister(NRF24L01_CONFIG, 0x0f); // Set PWR_UP bit, enable CRC(2 uint8_ts) & Prim:RX. RX_DR enabled..

	nRF24L01_writeCEPin(1); // Set CE pin high to enable RX device

	//  This device is now ready to receive one packet of 16 uint8_ts payload from a TX device sending to address
	//  '3443101001', with auto acknowledgment, retransmit count of 10, RF channel 40 and datarate = 2Mbps.
	return NRF24L01_STATE_SUCCESS;
}

uint8_t nRF24L01_readStatus(void) {
	return nRF24L01_Read(NRF24L01_STATUS);	// Read STATUS
}

void L01_Set_Channel(uint8_t rf_ch)                            // Set RF channel
		{
	nRF24L01_writeRegister(NRF24L01_RF_CH, rf_ch);
}

uint8_t L01_Get_Channel(void)                          // Get current RF channel
		{
	return nRF24L01_Read(NRF24L01_RF_CH);
}

uint8_t L01_Clear_IRQ(uint8_t irq_flag){            // Clear nRF24L01 IRQ flag(s)
	return nRF24L01_writeRegister(NRF24L01_STATUS, irq_flag);
}

void L01_Write_TX_Pload(uint8_t *pBuf, uint8_t plWidth) // Write TX payload, payload in *pBuf & #of uint8_ts = plWidth
		{
	nRF24L01_Write_Buf(NRF24L01_WR_TX_PLOAD, pBuf, plWidth);
}

uint8_t L01_Get_Status(void)                              // Read status uint8_t
		{
	return nRF24L01_Read(NRF24L01_STATUS);
}

uint8_t L01_RD_RX_PW_n(uint8_t pipe)  // Get current RX payload width for pipe.n
		{
	return nRF24L01_Read(NRF24L01_RX_PW_P0 + pipe);
}

void L01_WR_RX_PW_n(uint8_t pipe, uint8_t plWidth) // Set RX payload width for pipe.n
		{
	nRF24L01_writeRegister(NRF24L01_RX_PW_P0 + pipe, plWidth);
}

uint8_t L01_Get_Current_Pipenum(void)                       // Get current pipe#
		{
	return ((L01_Get_Status() & NRF24L01_RX_P_NO) >> 1);
}

uint16_t L01_Read_RX_Pload(uint8_t *pBuf) {    // read current pipe#'s RX payload
	uint8_t plWidth, pipe;
	plWidth = L01_RD_RX_PW_n(pipe = L01_Get_Current_Pipenum()); // Read current pipe's payload width
	nRF24L01_Read_Buf(NRF24L01_RD_RX_PLOAD, pBuf, plWidth);             // Then get RX data

	return ((pipe << 8) + plWidth);                // return pipe# & pipe#.plWidth
}

void L01_Flush_TX(void)                                         // Flush TX FIFO
		{
	nRF24L01_writeRegister(NRF24L01_FLUSH_TX, 0);
}

void L01_Flush_RX(void)                                         // Flush RX FIFO
		{
	nRF24L01_writeRegister(NRF24L01_FLUSH_RX, 0);
}

uint8_t L01_Get_FIFO(void)                          // Read FIFO_STATUS register
		{
	return nRF24L01_Read(NRF24L01_FIFO_STATUS);
}

void nRF24L01_getAllRegisters (uint8_t *registers) {
	for (uint8_t loop = 0; loop < 0x17; loop++) {	// For debug purpose, will be commented after unit tests
		*registers++ = nRF24L01_Read(loop);
	}
}

