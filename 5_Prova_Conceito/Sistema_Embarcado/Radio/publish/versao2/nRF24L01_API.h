/** @file API.h
 *
 * @author Runar Kjellhaug
 *
 * @compiler This program has been tested with Keil C51 V7.50.
 *
 *
 * $Date: 31.01.06 14:14 $
 * $Revision: 13 $
 *
 */
// uint8_t type definition
#ifndef _uint8_t_DEF_
#define _uint8_t_DEF_
typedef unsigned char uint8_t;
#endif   /* _uint8_t_DEF_ */

// Macro to read SPI Interrupt flag
#define WAIT_SPIF (!(SPI0CN & 0x80))  // SPI interrupt flag(µC platform dependent)

#define RX_P_NO             0x0e

// Declare SW/HW SPI modes
#define SW_MODE         0x00
#define HW_MODE         0x01

// Define nRF24L01 interrupt flag's
#define IDLE            0x00  // Idle, no interrupt pending
#define MAX_RT          0x10  // Max #of TX retrans interrupt
#define TX_DS           0x20  // TX data sent interrupt
#define RX_DR           0x40  // RX data received

#define SPI_CFG         0x40  // SPI Configuration register value
#define SPI_CTR         0x01  // SPI Control register values
#define SPI_CLK         0x00  // SYSCLK/2*(SPI_CLK+1) == > 12MHz / 2 = 6MHz
#define SPI0E           0x02  // SPI Enable in XBR0 register

//********************************************************************************************************************//
// SPI(nRF24L01) commands
#define READ_REG        0x00  // Define read command to register
#define WRITE_REG       0x20  // Define write command to register
#define RD_RX_PLOAD     0x61  // Define RX payload register address
#define WR_TX_PLOAD     0xA0  // Define TX payload register address
#define FLUSH_TX        0xE1  // Define flush TX register command
#define FLUSH_RX        0xE2  // Define flush RX register command
#define REUSE_TX_PL     0xE3  // Define reuse TX payload register command
#define NOP             0xFF  // Define No Operation, might be used to read status register

//********************************************************************************************************************//
// SPI(nRF24L01) registers(addresses)
#define CONFIG          0x00  // 'Config' register address
#define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
#define SETUP_AW        0x03  // 'Setup address width' register address
#define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
#define RF_CH           0x05  // 'RF channel' register address
#define RF_SETUP        0x06  // 'RF setup' register address
#define STATUS          0x07  // 'Status' register address
#define OBSERVE_TX      0x08  // 'Observe TX' register address
#define CD              0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
#define TX_ADDR         0x10  // 'TX address' register address
#define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS     0x17  // 'FIFO Status Register' register address

typedef enum {
	NRF24L01_STATE_SUCCESS 									= 0,
	NRF24L01_STATE_FAIL_INIT 								= 1,
	NRF24L01_STATE_FAIL_INVALID_INPUT				= 2,
} NRF24L01_state_t;

typedef struct {
	uint8_t* payload;
	uint8_t address[5];
	uint8_t payloadWidth;
	uint8_t addressLength;
}NRF24L01_transferSetupStruct_t;

//********************************************************************************************************************//
//                                        FUNCTION's PROTOTYPES                                                       //
//********************************************************************************************************************//
NRF24L01_state_t nRF24L01_Init(void);                       // Init HW or SW SPI
NRF24L01_state_t nRF24L01_transmitPayload( NRF24L01_transferSetupStruct_t* setup );
NRF24L01_state_t nRF24L01_receivePayload( NRF24L01_transferSetupStruct_t* setup );

uint8_t nRF24L01_readStatus(void);
uint8_t L01_Clear_IRQ(uint8_t irq_flag);

uint16_t L01_Read_RX_Pload(uint8_t *pBuf);

void nRF24L01_getAllRegisters (uint8_t* registers);

//********************************************************************************************************************//
