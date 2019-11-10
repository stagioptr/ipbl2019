/*
 * mpu6050.h
 *
 *  Created on: Oct 15, 2019
 *      Author: Joao Mendes
 *      Implements a Driver for the MPU6050 accelerometer/gyroscope.
 *      Refenres Documents:
 *      http://www.jarzebski.pl/arduino/czujniki-i-sensory/3-osiowy-zyroskop-i-akcelerometr-mpu6050.html
 *      https://github.com/jarzebski/Arduino-MPU6050
 *      I2Cdev library collection - MPU6050 I2C device class
 *      https://github.com/jrowberg/i2cdevlib
 *
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
#define MPU6050_REG_INT_STATUS 0x3A

#define MPU6050_I2C_SLV1_CTRL 0x2A

//Accel Hight
#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_ACCEL_YOUT_H 0x3D
#define MPU6050_ACCEL_ZOUT_H 0x3F

//Accel Low
#define MPU6050_ACCEL_XOUT_L 0x3C
#define MPU6050_ACCEL_YOUT_L 0x3E
#define MPU6050_ACCEL_ZOUT_L 0x40

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

//#define MPU6050_DHPF_RESET          0x00
//#define MPU6050_DHPF_5              0x01
//#define MPU6050_DHPF_2P5            0x02
//#define MPU6050_DHPF_1P25           0x03
//#define MPU6050_DHPF_0P63           0x04
//#define MPU6050_DHPF_HOLD           0x07

#define MPU6050_ACONFIG_XA_ST_BIT           7
#define MPU6050_ACONFIG_YA_ST_BIT           6
#define MPU6050_ACONFIG_ZA_ST_BIT           5
#define MPU6050_ACONFIG_AFS_SEL_BIT         4
#define MPU6050_ACONFIG_AFS_SEL_LENGTH      2
#define MPU6050_ACONFIG_ACCEL_HPF_BIT       2
#define MPU6050_ACONFIG_ACCEL_HPF_LENGTH    3

#define MPU6050_REG_MOT_DETECT_CTRL 0x69

#define MPU6050_WHO_AM_I 0x75 //O número padrão é 0x68

typedef enum
{
    MPU6050_DELAY_3MS             = 0b11,
    MPU6050_DELAY_2MS             = 0b10,
    MPU6050_DELAY_1MS             = 0b01,
    MPU6050_NO_DELAY              = 0b00,
} mpu6050_onDelay_t;


typedef enum
{
    MPU6050_DHPF_HOLD             = 0b111,
    MPU6050_DHPF_0_63HZ           = 0b100,
    MPU6050_DHPF_1_25HZ           = 0b011,
    MPU6050_DHPF_2_5HZ            = 0b010,
    MPU6050_DHPF_5HZ              = 0b001,
    MPU6050_DHPF_RESET            = 0b000,
} mpu6050_dhpf_t;

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

uint8_t MPU6050_GetAccelXYZ(uint8_t* a_x, uint8_t* a_y, uint8_t* a_z);

uint8_t MPU6050_GetGyroXYZ(uint8_t* x, uint8_t* y, uint8_t* z);

uint8_t MPU6050_GetTemperature(void);

uint8_t MPU6050_GetFreeFallDetectionThreshold(uint8_t* threshold);

uint8_t MPU6050_SetFreeFallDetectionThreshold(uint8_t threshold);

uint8_t MPU6050_GetFreeFallDetectionDuration(uint8_t* duration);

uint8_t MPU6050_SetFreeFallDetectionDuration(uint8_t duration);

uint8_t MPU6050_ReadReg8(uint8_t addr, uint8_t *val);

uint8_t MPU6050_ReadReg16(uint8_t addr, uint16_t *val);

uint8_t MPU6050_WriteReg8(uint8_t addr, uint8_t val);

uint8_t MPU6050_SetAccelPowerOnDelay(mpu6050_onDelay_t delay);

uint8_t MPU6050_WriteRegisterBit(uint8_t reg, uint8_t pos, uint8_t value);

uint8_t MPU6050_SetDeviceReset(uint8_t value);

uint8_t MPU6050_SetIntFreeFallEnabled(uint8_t value);

uint8_t MPU6050_SetIntZeroMotionEnabled(uint8_t value);

uint8_t MPU6050_SetIntMotionEnabled(uint8_t value);

uint8_t MPU6050_SetDHPFMode(mpu6050_dhpf_t dhpf);

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

uint8_t MPU6050_ReadActivites(uint8_t* is_free_fall);

uint8_t init_example();

#endif /* MPU6050_H_ */
