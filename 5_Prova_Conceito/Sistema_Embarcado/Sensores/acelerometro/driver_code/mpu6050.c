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
	.baudRate_kbps = 200,
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
	//local variables
	uint8_t pwr = 0x00;
	uint8_t smplrt = 0x13;
	uint8_t config = 0x02;
	uint8_t gyro_config = 0x18;
	uint8_t accel_config = 0x01;
	uint8_t interrupt_config = 0x30;
	uint8_t interrupt_enable = 0x01;

	//return variables
	uint8_t rt_pwr;
	uint8_t rt_smplrt;
	uint8_t rt_config;
	uint8_t rt_gyro_config;
	uint8_t rt_accel_config;
	uint8_t rt_interrupt_config;
	uint8_t rt_interrupt_enable;

	rt_pwr = MPU6050_WriteReg8(MPU6050_PWR_MGMT_1, pwr);
	rt_smplrt = MPU6050_WriteReg8(MPU6050_SMPLRT_DIV, smplrt);
	rt_config = MPU6050_WriteReg8(MPU6050_CONFIG, config);
	rt_gyro_config = MPU6050_WriteReg8(MPU6050_GYRO_CONFIG, gyro_config);
	rt_accel_config = MPU6050_WriteReg8(MPU6050_ACCEL_CONFIG, accel_config);
	rt_interrupt_config = MPU6050_WriteReg8(MPU6050_INT_CONFIGURATION, interrupt_config);
	rt_interrupt_enable = MPU6050_WriteReg8(MPU6050_INTERRUPT_ENABLE, interrupt_enable);

	//MPU6050_WriteReg8( MPU6050_CTRL_REG_2, 0x40 );
  //static const uint8_t addr = MMA1_CTRL_REG_1;
  //static const uint8_t addr = MPU6050_I2C_SLV1_CTRL;
  //static const uint8_t val = MMA1_ACTIVE_BIT_MASK | MMA1_F_READ_BIT_MASK;
  //static const uint8_t val = MPU6050_ACTIVE_BIT_MASK | MPU6050_F_READ_BIT_MASK;


  //sCalValues.NxOff = InitialCalibration.NxOff;
  //sCalValues.NyOff = InitialCalibration.NyOff;
  //sCalValues.NzOff = InitialCalibration.NzOff;

  //return I2C_DRV_MasterSendDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)&val, sizeof(val), 20 );
  //MMA1_I2C_ADDR, (uint8_t*)&addr, sizeof(addr), &xyz[0], 3);
  //return I2C_DRV_MasterSendDataBlocking(MMA1_I2C_ADDR, MMA1_CTRL_REG_1, MMA1_ACTIVE_BIT_MASK); /* enable device */
	if((rt_pwr == kStatus_I2C_Success) && (rt_smplrt == kStatus_I2C_Success) && (rt_config == kStatus_I2C_Success) && (rt_gyro_config == kStatus_I2C_Success) && (rt_accel_config == kStatus_I2C_Success) && (rt_interrupt_config == kStatus_I2C_Success) && (rt_interrupt_enable == kStatus_I2C_Success)){
		return kStatus_I2C_Success;
	} else {
		return kStatus_I2C_Fail;
	}
}

uint8_t MPU6050_ReadReg8(uint8_t addr, uint8_t *val)
{
  if( I2C_DRV_MasterReceiveDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)val, sizeof(*val), 10 ) ) {
  //if (I2C_DRV_MasterReceiveDataBlocking(MMA1_I2C_ADDR, addr, val)!=kStatus_I2C_Success) {
    return kStatus_I2C_Fail;
  }
  return kStatus_I2C_Success;
}

/*
** ===================================================================
**     Method      :  MMA1_WriteReg8 (component MMA8451Q)
**     Description :
**         Write an 8bit device register
**     Parameters  :
**         NAME            - DESCRIPTION
**         addr            - device memory map address
**         val             - value to write
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t MPU6050_WriteReg8(uint8_t addr, uint8_t val)
{
  return I2C_DRV_MasterSendDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)&val, sizeof(val), 20 );
  //  return I2C_DRV_MasterSendDataBlocking(MMA1_I2C_ADDR, addr, val);
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
uint8_t MPU6050_WhoAmI()
{
  static const uint8_t addr = MPU6050_WHO_AM_I;
  uint8_t value;
  uint8_t rt;

  rt = I2C_DRV_MasterReceiveDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)&value, sizeof(value), 20 );
  //return I2C_DRV_MasterReceiveDataBlocking(MPU6050_I2C_ADDRESS, MPU6050_WHO_AM_I, value);
  if(rt == kStatus_I2C_Success){
	  return value;
  } else {
	  return rt;
  }
}

uint8_t init_example(){
	uint8_t temporario = 1;
	return temporario;
}

uint8_t read_test()
{
	uint8_t cmd=0x3b; //register address

	uint8_t count=6;

	uint8_t buffer[10];

  return( I2C_DRV_MasterReceiveDataBlocking( I2C1_IDX, &mpu6050_parameters, &cmd,1,&buffer[0],count,1000) );

}
