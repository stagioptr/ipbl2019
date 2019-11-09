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
#include "gpio1.h"
#include "Radio1.h"
#include "Radio2.h"
#include "task.h"
#include "fsl_os_abstraction_free_rtos.h"

extern task_handler_t TaskRadio1_task_handler;
extern task_handler_t TaskRadio2_task_handler;

semaphore_t nRF24L01_Radio1_IRQ = NULL;
semaphore_t nRF24L01_Radio2_IRQ = NULL;

const gpio_output_pin_user_config_t gpio1_OutRadio1[] = {
  {
    .pinName = CSN_Radio1,
    .config.outputLogic = 1,
    .config.slewRate = kPortFastSlewRate,
    .config.driveStrength = kPortHighDriveStrength,
  },
  {
    .pinName = CE_Radio1,
    .config.outputLogic = 1,
    .config.slewRate = kPortFastSlewRate,
    .config.driveStrength = kPortHighDriveStrength,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_input_pin_user_config_t gpio1_DeinitRadio1[] = {
  {
    .pinName = CSN_Radio1,
		.config.isPullEnable = false,
		.config.isPassiveFilterEnabled = false,
		.config.interrupt = kPortIntDisabled
  },
  {
    .pinName = CE_Radio1,
		.config.isPullEnable = false,
		.config.isPassiveFilterEnabled = false,
		.config.interrupt = kPortIntDisabled
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_output_pin_user_config_t gpio1_OutRadio2[] = {
  {
    .pinName = CSN_Radio2,
    .config.outputLogic = 1,
    .config.slewRate = kPortFastSlewRate,
    .config.driveStrength = kPortHighDriveStrength,
  },
  {
    .pinName = CE_Radio2,
    .config.outputLogic = 1,
    .config.slewRate = kPortFastSlewRate,
    .config.driveStrength = kPortHighDriveStrength,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_input_pin_user_config_t gpio1_DeinitRadio2[] = {
  {
    .pinName = CSN_Radio2,
		.config.isPullEnable = false,
		.config.isPassiveFilterEnabled = false,
		.config.interrupt = kPortIntDisabled
  },
  {
    .pinName = CE_Radio2,
		.config.isPullEnable = false,
		.config.isPassiveFilterEnabled = false,
		.config.interrupt = kPortIntDisabled
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

spi_master_state_t Radio1_MasterState;
uint32_t Radio1_calculatedBaudRate = 0;

spi_master_state_t Radio2_MasterState;
uint32_t Radio2_calculatedBaudRate = 0;

bool nRF24L01_SPI_Init_port() {
	bool retVal = true;

	if (xTaskGetCurrentTaskHandle() == TaskRadio1_task_handler) {
		GPIO_DRV_Init(NULL,gpio1_OutRadio1);

		retVal &= (SPI_DRV_MasterInit(Radio1_IDX, &Radio1_MasterState) == kStatus_SPI_Success) ? 1 : 0;
		SPI_DRV_MasterConfigureBus(Radio1_IDX, &Radio_MasterConfig0, &Radio1_calculatedBaudRate);
	} else if (xTaskGetCurrentTaskHandle() == TaskRadio2_task_handler) {
		GPIO_DRV_Init(NULL,gpio1_OutRadio2);

		retVal &= (SPI_DRV_MasterInit(Radio2_IDX, &Radio2_MasterState) == kStatus_SPI_Success) ? 1 : 0;
		SPI_DRV_MasterConfigureBus(Radio2_IDX, &Radio_MasterConfig0, &Radio2_calculatedBaudRate);
	} else {
		return false;
	}

	return retVal;
}

bool nRF24L01_SPI_Deinit_port() {
	bool retVal = true;

	if (xTaskGetCurrentTaskHandle() == TaskRadio1_task_handler) {
		GPIO_DRV_Init(gpio1_DeinitRadio1,NULL);

		retVal &= (SPI_DRV_MasterDeinit(Radio1_IDX) == kStatus_SPI_Success) ? 1 : 0;
	} else if (xTaskGetCurrentTaskHandle() == TaskRadio2_task_handler) {
		GPIO_DRV_Init(gpio1_DeinitRadio2,NULL);

		retVal &= (SPI_DRV_MasterDeinit(Radio2_IDX) == kStatus_SPI_Success) ? 1 : 0;
	} else {
		return false;
	}

	return retVal;
}

const gpio_input_pin_user_config_t gpio1_InpRadio1[] = {
  {
    .pinName = IRQ_Radio1,
    .config.isPullEnable = true,
    .config.isPassiveFilterEnabled = true,
    .config.interrupt = kPortIntFallingEdge
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_input_pin_user_config_t gpio1_InpDeinitRadio1[] = {
  {
    .pinName = IRQ_Radio1,
    .config.isPullEnable = false,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntDisabled
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_input_pin_user_config_t gpio1_InpRadio2[] = {
  {
    .pinName = IRQ_Radio2,
    .config.isPullEnable = true,
    .config.isPassiveFilterEnabled = true,
    .config.interrupt = kPortIntFallingEdge
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

const gpio_input_pin_user_config_t gpio1_InpDeinitRadio2[] = {
  {
    .pinName = IRQ_Radio2,
    .config.isPullEnable = false,
    .config.isPassiveFilterEnabled = false,
    .config.interrupt = kPortIntDisabled
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

bool nRF24L01_EXTI_Init_port() {

	if (xTaskGetCurrentTaskHandle() == TaskRadio1_task_handler) {
		GPIO_DRV_Init(gpio1_InpRadio1,NULL);
		nRF24L01_Radio1_IRQ = xSemaphoreCreateBinary();
	} else if (xTaskGetCurrentTaskHandle() == TaskRadio2_task_handler) {
		GPIO_DRV_Init(gpio1_InpRadio2,NULL);
		nRF24L01_Radio2_IRQ = xSemaphoreCreateBinary();
	} else {
		return false;
	}

	return true;
}

bool nRF24L01_EXTI_Deinit_port() {

	if (xTaskGetCurrentTaskHandle() == TaskRadio1_task_handler) {
		GPIO_DRV_Init(gpio1_InpDeinitRadio1,NULL);
		vSemaphoreDelete( nRF24L01_Radio1_IRQ );
	} else if (xTaskGetCurrentTaskHandle() == TaskRadio2_task_handler) {
		GPIO_DRV_Init(gpio1_InpDeinitRadio2,NULL);
		vSemaphoreDelete( nRF24L01_Radio2_IRQ );
	} else {
		return false;
	}

	return true;
}

/*
 #define nRF24L01_SPI_TransferBlocking(TX_BUFFER,RX_BUFFER,LENGTH) 		SPI_DRV_MasterTransferBlocking(SPI_ID, &Radio_MasterConfig0, TX_BUFFER, RX_BUFFER, LENGTH, 20);

 #define nRF24L01_writeChpSelectPin( STATE )														GPIO_DRV_WritePinOutput(J2_6, STATE);
 #define nRF24L01_writeCEPin( STATE )																	GPIO_DRV_WritePinOutput(J1_8, STATE);

 */

void nRF24L01_SPI_TransferBlocking(uint8_t* TX_BUFFER, uint8_t* RX_BUFFER,
		uint8_t LENGTH) {
	if (xTaskGetCurrentTaskHandle() == TaskRadio1_task_handler) {
		SPI_DRV_MasterTransferBlocking(0, &Radio_MasterConfig0, TX_BUFFER, RX_BUFFER, LENGTH, 20);
	} else {
		SPI_DRV_MasterTransferBlocking(1, &Radio_MasterConfig0, TX_BUFFER, RX_BUFFER, LENGTH, 20);
	}
}

void nRF24L01_writeChpSelectPin(uint8_t STATE) {
	if (xTaskGetCurrentTaskHandle() == TaskRadio1_task_handler) {
		GPIO_DRV_WritePinOutput(CSN_Radio1, STATE);
	} else {
		GPIO_DRV_WritePinOutput(CSN_Radio2, STATE);
	}
}
void nRF24L01_writeCEPin(uint8_t STATE) {
	if (xTaskGetCurrentTaskHandle() == TaskRadio1_task_handler) {
		GPIO_DRV_WritePinOutput(CE_Radio1, STATE);
	} else {
		GPIO_DRV_WritePinOutput(CE_Radio2, STATE);
	}
}
