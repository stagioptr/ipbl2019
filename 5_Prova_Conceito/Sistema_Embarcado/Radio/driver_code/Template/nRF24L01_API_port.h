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

const spi_master_user_config_t Radio_MasterConfig0 = {
	.bitsPerSec = 2000000U,
	.polarity = kSpiClockPolarity_ActiveHigh,
	.phase = kSpiClockPhase_FirstEdge,
	.direction = kSpiMsbFirst
};

spi_master_state_t Radio_MasterState;
uint32_t Radio_calculatedBaudRate = 0;

void nRF24L01_Init(uint32_t SPI_ID) {
	SPI_DRV_MasterInit(SPI_ID, &Radio_MasterState);
	SPI_DRV_MasterConfigureBus(SPI_ID, &Radio_MasterConfig0,
			&Radio_calculatedBaudRate);
}
