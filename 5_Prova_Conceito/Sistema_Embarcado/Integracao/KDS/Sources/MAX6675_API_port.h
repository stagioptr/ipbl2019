/** @file MAX6675_API_port.h
 *
 * @author Vítor Cruz
 *
 * @brief MAX6675 K-Thermocouple library.
 */

#include "fsl_spi_master_driver.h"
#include "fsl_gpio_driver.h"
#include "gpio.h"
#include "task.h"
#include "fsl_os_abstraction_free_rtos.h"
#include "spiRadioTemp.h"

extern semaphore_t SPI0_Semaphore;

#define MAX6675_BIG_ENDIAN													1

#define  MAX6675_SPI_Init_port()										1

#define MAX6675_SPI_TransferBlocking(RX_BUFFER,LENGTH) ( SPI_DRV_MasterTransferBlocking(spiRadioTemp_IDX, &spiRadioTemp_MasterConfig0, RX_BUFFER, RX_BUFFER, LENGTH, 20) == kStatus_SPI_Success )

#define MAX6675_writeChipSelectPin( STATE ) 						\
{																												\
	if( STATE )	{																					\
		xSemaphoreGive( SPI0_Semaphore ); 									\
	}																											\
	else {																								\
		xSemaphoreTake( SPI0_Semaphore, portMAX_DELAY ); 		\
	}																											\
	GPIO_DRV_WritePinOutput(Temp_CSN, STATE); 						\
}
