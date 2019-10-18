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

#define MPU6050_SYS_MODE_REG	0x0B

#define MPU6050_CTRL_REG_2 0x2B

#define MPU6050_CTRL_REG_4 0x2D
#define MPU6050_CTRL_REG_5 0x2E

#define MPU6050_ACTIVE_BIT_MASK 0x01
#define MPU6050_F_READ_BIT_MASK 0x02

#define MPU6050_I2C_SLV1_CTRL 0x2A

#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_ACCEL_YOUT_H 0x3D
#define MPU6050_ACCEL_ZOUT_H 0x3F

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

uint8_t MPU6050_WhoAmI(uint8_t *value);
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

uint8_t read_test();

uint8_t init_example();

#endif /* MPU6050_H_ */
