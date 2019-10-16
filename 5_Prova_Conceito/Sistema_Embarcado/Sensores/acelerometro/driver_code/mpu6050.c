/*
 * mpu6050.h
 *
 *  Created on: Oct 15, 2019
 *      Author: Joao Mendes
 *      Implements a Driver for the MPU6050 accelerometer/gyroscope.
 */

//#include "stdint.h"
#include "mpu6050.h"

#define ERR_RANGE 230
#define FALSE		0
#define TRUE		1

const i2c_device_t mpu6050_parameters = {
	.address = MPU6050_I2C_ADDRESS,
	.baudRate_kbps = 400000
};

/*
** ===================================================================
**     Method      :  MMA1_WhoAmI (component MMA8451Q)
**     Description :
**         Returns the value of the WHO_AM_I (0x0D) register
**     Parameters  :
**         NAME            - DESCRIPTION
**       * value           - Pointer to value to store
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t MPU6050_WhoAmI(uint8_t *value)
{
  static const uint8_t addr = MPU6050_WHO_AM_I;

  return I2C_DRV_MasterReceiveDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)&value, sizeof(value), 20 );

  //return I2C_DRV_MasterReceiveDataBlocking(MMA1_I2C_ADDR, MMA1_WHO_AM_I, value);
}

uint8_t mpu6050_init(){
	uint8_t temporario = 1;
	return temporario;
}

