/** @file MAX6675_API_port.h
 *
 * @author Vítor Cruz
 *
 * @brief MAX6675 K-Thermocouple library.
 */

#include "fsl_spi_master_driver.h"
#include "fsl_gpio_driver.h"
#include "gpio1.h"

#define MAX6675_BIG_ENDIAN													1

#define spiTemp_IDX SPI0_IDX

const gpio_output_pin_user_config_t gpio1_OutTemp[] = {
  {
    .pinName = tempCSN,
    .config.outputLogic = 1,
    .config.slewRate = kPortFastSlewRate,
    .config.driveStrength = kPortHighDriveStrength,
  },
  {
    .pinName = GPIO_PINS_OUT_OF_RANGE,
  }
};

spi_master_state_t spiTemp_MasterState;
uint32_t spiTemp_calculatedBaudRate = 0;

const spi_master_user_config_t spiTemp_MasterConfig0 = {
  .bitsPerSec = 4000000U,
  .polarity = kSpiClockPolarity_ActiveHigh,
  .phase = kSpiClockPhase_FirstEdge,
  .direction = kSpiMsbFirst,
};

bool MAX6675_SPI_Init_port (void) {
	bool retVal = true;

  GPIO_DRV_Init(NULL,gpio1_OutTemp);

  retVal &=
  			(SPI_DRV_MasterInit(spiTemp_IDX, &spiTemp_MasterState) == kStatus_SPI_Success) ? 1 : 0;
  SPI_DRV_MasterConfigureBus(spiTemp_IDX, &spiTemp_MasterConfig0, &spiTemp_calculatedBaudRate);

  return retVal;
}

bool MAX6675_SPI_TransferBlocking(uint8_t* RX_BUFFER, uint8_t LENGTH) {
	if( SPI_DRV_MasterTransferBlocking(spiTemp_IDX, &spiTemp_MasterConfig0, RX_BUFFER, RX_BUFFER, LENGTH, 20) != kStatus_SPI_Success )
		return false;
	else
		return true;
}

void nRF24L01_writeChpSelectPin(uint8_t STATE) {
	GPIO_DRV_WritePinOutput(tempCSN, STATE);
}
