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

#define MPU6050_ACTIVE_BIT_MASK 0x01
#define MPU6050_F_READ_BIT_MASK 0x02

#define MPU6050_I2C_SLV1_CTRL 0x2A

#define MPU6050_WHO_AM_I 0x75 //O número padrão é 0x68

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

uint8_t init_example();


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

#endif /* MPU6050_H_ */
