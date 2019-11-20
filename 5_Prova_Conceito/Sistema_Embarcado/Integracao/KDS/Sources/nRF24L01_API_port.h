/*
 ******************************************************************************
 * @file    nRF24L01_API_port.c
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    10-Outubro-2019
 * @brief   Máquina de estados para tratamento de sensor genérico.
 ******************************************************************************
 */

#include "fsl_spi_master_driver.h"
#include "fsl_gpio_driver.h"
#include "gpio.h"
#include "task.h"
#include "fsl_os_abstraction_free_rtos.h"
#include "spiRadioTemp.h"

extern semaphore_t nRF24L01_Radio_IRQ;
extern semaphore_t SPI0_Semaphore;

#define nRF24L01_SPI_Init_port()  						1

#define nRF24L01_SPI_Deinit_port() 						1

#define nRF24L01_EXTI_Init_port() 						1

#define nRF24L01_EXTI_Deinit_port() 					1

#define nRF24L01_SPI_TransferBlocking(TX_BUFFER,RX_BUFFER,LENGTH) 		SPI_DRV_MasterTransferBlocking(spiRadioTemp_IDX, &spiRadioTemp_MasterConfig0, TX_BUFFER, RX_BUFFER, LENGTH, 20)

#define nRF24L01_writeChipSelectPin( STATE ) 						\
{																												\
	if( STATE )	{																					\
		OSA_SemaPost( &SPI0_Semaphore ); 										\
	}																											\
	else {																								\
		OSA_SemaWait( SPI0_Semaphore, OSA_WAIT_FOREVER ); 	\
	}																											\
	GPIO_DRV_WritePinOutput(Radio_CSN, STATE); 						\
}


#define nRF24L01_writeCEPin( STATE )																	GPIO_DRV_WritePinOutput(Radio_CE, STATE);

