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
#include "spiRadio.h"
#include "task.h"
#include "fsl_os_abstraction_free_rtos.h"

semaphore_t nRF24L01_Radio_IRQ = NULL;

const gpio_output_pin_user_config_t gpio_OutRadio[] = {
  {
    .pinName = CSN_Radio,
    .config.outputLogic = 1,
    .config.slewRate = kPortFastSlewRate,
    .config.driveStrength = kPortHighDriveStrength,
  },
  {
    .pinName = CE_Radio,
    .config.outputLogic = 1,
    .config.slewRate = kPortFastSlewRate,
    .config.driveStrength = kPortHighDriveStrength,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const spi_master_user_config_t Radio_MasterConfig0 = {
	.bitsPerSec = 2000000U,
	.polarity = kSpiClockPolarity_ActiveHigh,
	.phase = kSpiClockPhase_FirstEdge,
	.direction = kSpiMsbFirst
};

spi_master_state_t Radio_MasterState;
uint32_t Radio_calculatedBaudRate = 0;

bool nRF24L01_SPI_Init_port() {
	bool retVal = true;

	GPIO_DRV_Init(NULL,gpio_OutRadio);

	retVal &=
			(SPI_DRV_MasterInit(spiRadio_IDX, &Radio_MasterState) == kStatus_SPI_Success) ? 1 : 0;
	SPI_DRV_MasterConfigureBus(spiRadio_IDX, &Radio_MasterConfig0,&Radio_calculatedBaudRate);

	return retVal;
}

const gpio_input_pin_user_config_t gpio1_InpRadio[] = {
  {
    .pinName = IRQ_Radio,
    .config.isPullEnable = true,
    .config.isPassiveFilterEnabled = true,
    .config.interrupt = kPortIntFallingEdge
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

bool nRF24L01_EXTI_Init_port() {

	GPIO_DRV_Init(gpio1_InpRadio,NULL);
	nRF24L01_Radio_IRQ = xSemaphoreCreateBinary();

	return true;
}


#define nRF24L01_SPI_TransferBlocking(TX_BUFFER,RX_BUFFER,LENGTH) 		SPI_DRV_MasterTransferBlocking(spiRadio_IDX, &Radio_MasterConfig0, TX_BUFFER, RX_BUFFER, LENGTH, 20);

#define nRF24L01_writeChpSelectPin( STATE )														GPIO_DRV_WritePinOutput(CSN_Radio, STATE);
#define nRF24L01_writeCEPin( STATE )																	GPIO_DRV_WritePinOutput(CE_Radio, STATE);

