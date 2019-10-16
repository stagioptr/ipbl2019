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

typedef struct {
  int16_t NxOff; /* offset for X axis */
  int16_t NyOff; /* offset for Y axis */
  int16_t NzOff; /* offset for Z axis */
} tAccelCal;

/* default calibration values from component properties */
static const tAccelCal InitialCalibration = { /* Initial default calibration values */
  0, /* X offset */
  0, /* Y offset */
  0, /* Z offset */
};
static tAccelCal sCalValues; /* calibration values in RAM */

#define CalNxOff   sCalValues.NxOff
#define CalNyOff   sCalValues.NyOff
#define CalNzOff   sCalValues.NzOff

/*
** ===================================================================
**     Method      :  MPU6050_Deinit (component MPU6050)
**     Description :
**         Counterpart to Init() method.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, kStatus_I2C_Success if everything is ok.
** ===================================================================
*/
uint8_t MPU6050_Deinit(void)
{
  return kStatus_I2C_Success; /* nothing to do */
}

/*
** ===================================================================
**     Method      :  MPU6050_Init (component MPU6050)
**     Description :
**         Initializes the device driver
**     Parameters  : None
**     Returns     :
**         ---             - Error code, kStatus_I2C_Success if everything is ok.
** ===================================================================
*/
uint8_t MPU6050_Init(void)
{
  //static const uint8_t addr = MMA1_CTRL_REG_1;
  static const uint8_t addr = MPU6050_I2C_SLV1_CTRL;
  //static const uint8_t val = MMA1_ACTIVE_BIT_MASK | MMA1_F_READ_BIT_MASK;
  static const uint8_t val = MPU6050_ACTIVE_BIT_MASK | MPU6050_F_READ_BIT_MASK;

  sCalValues.NxOff = InitialCalibration.NxOff;
  sCalValues.NyOff = InitialCalibration.NyOff;
  sCalValues.NzOff = InitialCalibration.NzOff;

  return I2C_DRV_MasterSendDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)&val, sizeof(val), 20 );
  //MMA1_I2C_ADDR, (uint8_t*)&addr, sizeof(addr), &xyz[0], 3);
  //return I2C_DRV_MasterSendDataBlocking(MMA1_I2C_ADDR, MMA1_CTRL_REG_1, MMA1_ACTIVE_BIT_MASK); /* enable device */
}

/*
** ===================================================================
**     Method      :  MPU6050_WhoAmI (component MPU6050)
**     Description :
**         Returns the value of the WHO_AM_I (0x68) register
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

  //return I2C_DRV_MasterReceiveDataBlocking(MPU6050_I2C_ADDRESS, MPU6050_WHO_AM_I, value);
}

uint8_t init_example(){
	uint8_t temporario = 1;
	return temporario;
}

