/*
 * mpu6050.h
 *
 *  Created on: Oct 15, 2019
 *      Author: Joao Mendes
 *      Implements a Driver for the MPU6050 accelerometer/gyroscope.
 */

#ifndef MPU6050_H_
#define MPU6050_H_

/* MODULE MPU6050. */
#include "MPU6050config.h" /* configuration */
#include "fsl_i2c_master_driver.h"

#define MPU6050_I2C_ADDRESS (0x68) /* I2C slave device address as set in the properties */

#define MPU6050_SMPLRT_DIV 0x19
#define MPU6050_CONFIG 0x1A
#define MPU6050_GYRO_CONFIG 0x1B
#define MPU6050_ACCEL_CONFIG 0x1C

#define MPU6050_INT_CONFIGURATION 0x37
#define MPU6050_INTERRUPT_ENABLE 0x38

#define MPU6050_I2C_SLV1_CTRL 0x2A

#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_ACCEL_YOUT_H 0x3D
#define MPU6050_ACCEL_ZOUT_H 0x3F

#define MPU6050_TEMP_OUT_H 0x41

#define MPU6050_GYRO_XOUT_H 0x43
#define MPU6050_GYRO_YOUT_H 0x45
#define MPU6050_GYRO_ZOUT_H 0x47

#define MPU6050_PWR_MGMT_1 0x6B

//Gyro config						//Full Scale Range| LSB Sensitivity
#define MPU6050_GYRO_FS_250         0x00 //± 250 °/s  | 131 LSB/°/s
#define MPU6050_GYRO_FS_500         0x01 //± 500 °/s  | 65.5 LSB/°/s
#define MPU6050_GYRO_FS_1000        0x02 //± 1000 °/s | 32.8 LSB/°/s
#define MPU6050_GYRO_FS_2000        0x03 //± 2000 °/s | 16.4 LSB/°/s

//Acceleration (G)					//Full Scale Range | LSB Sensitivity
#define MPU6050_ACCEL_FS_2          0x00 //±2g 	       | 16384 LSB/g
#define MPU6050_ACCEL_FS_4          0x01 //±4g 		   | 8192 LSB/g
#define MPU6050_ACCEL_FS_8          0x02 //±8g 		   | 4096 LSB/g
#define MPU6050_ACCEL_FS_16         0x03 //±16g 	   | 2048 LSB/g

//Free Fall
#define MPU6050_FF_THR 0x1D
#define MPU6050_FF_DUR 0x1E

#define MPU6050_WHO_AM_I 0x75 //O número padrão é 0x68

uint8_t MPU6050_Deinit(void);
/*
** ===================================================================
**     Method      :  MPU6050_Deinit (component MPU6050)
**     Description :
**         Counterpart to Init() method.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, ERR_OK if everything is ok.
** ===================================================================
*/

uint8_t MPU6050_Init(void);
/*
** ===================================================================
**     Method      :  MPU6050_Init (component MPU6050)
**     Description :
**         Initializes the device driver
**     Parameters  : None
**     Returns     :
**         ---             - Error code, ERR_OK if everything is ok.
** ===================================================================
*/

uint8_t MPU6050_GetAccelXYZ(uint8_t* x, uint8_t* y, uint8_t* z);

uint8_t MPU6050_GetGyroXYZ(uint8_t* x, uint8_t* y, uint8_t* z);

uint8_t MPU6050_GetTemperature(void);

uint8_t MPU6050_GetFreeFallDetectionThreshold(uint8_t* threshold);

uint8_t MPU6050_ReadReg8(uint8_t addr, uint8_t *val);

uint8_t MPU6050_WriteReg8(uint8_t addr, uint8_t val);
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
uint8_t MPU6050_WhoAmI();
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

uint8_t init_example();

#endif /* MPU6050_H_ */
