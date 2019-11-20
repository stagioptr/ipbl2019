/*
 * mpu6050.h
 *
 *  Created on: Oct 15, 2019
 *      Author: Joao Mendes
 *      Implements a Driver for the MPU6050 accelerometer/gyroscope.
 */

//#include "stdint.h"
#include "mpu6050.h"
//#include "math.h"

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
	uint8_t whoami = 0x68;
	uint8_t pwr = 0x00;
	uint8_t smplrt = 0x19;
	uint8_t config = 0x02;
	uint8_t gyro_config = MPU6050_GYRO_FS_250;
	uint8_t accel_config = MPU6050_ACCEL_FS_16;
	uint8_t interrupt_config = 0x30;
	uint8_t interrupt_enable = 0x01;

	do {
		if (MPU6050_WhoAmI() != whoami) //get ID default value = 0x68
			break;
		if (MPU6050_WriteReg8(MPU6050_PWR_MGMT_1, pwr) != kStatus_I2C_Success) //set clock (0x00) = Internal 8MHz oscillator
			break;
		if (MPU6050_WriteReg8(MPU6050_SMPLRT_DIV, smplrt)  != kStatus_I2C_Success) //Accel 1Hhz (100 Hz) = 1000/1 + 19 = 50 Hz
			break;
		if (MPU6050_WriteReg8(MPU6050_CONFIG, config) != kStatus_I2C_Success)
			break;
		if (MPU6050_WriteReg8(MPU6050_GYRO_CONFIG, gyro_config) != kStatus_I2C_Success)
			break;
		if (MPU6050_WriteReg8(MPU6050_ACCEL_CONFIG, accel_config) != kStatus_I2C_Success)
			break;
		if (MPU6050_WriteReg8(MPU6050_INT_CONFIGURATION, interrupt_config) != kStatus_I2C_Success)
			break;
		if (MPU6050_WriteReg8(MPU6050_INTERRUPT_ENABLE, interrupt_enable) != kStatus_I2C_Success)
			break;
		return kStatus_I2C_Success;
	} while (1);
	return kStatus_I2C_Fail;
}

uint8_t MPU6050_ReadReg8(uint8_t addr, uint8_t *val)
{
  if( I2C_DRV_MasterReceiveDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)val, sizeof(*val), 20 ) ) {
    return kStatus_I2C_Fail;
  }
  return kStatus_I2C_Success;
}

/*
** ===================================================================
**     Method      :  MPU6050_WriteReg8 (component MPU6050)
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

uint8_t MPU6050_SetAccelPowerOnDelay(mpu6050_onDelay_t delay)
{
    uint8_t value;
    uint8_t read_status;
    uint8_t write_status;
    read_status = MPU6050_ReadReg8(MPU6050_REG_MOT_DETECT_CTRL, &value);
    if (read_status != kStatus_I2C_Success) {
    	return read_status != kStatus_I2C_Fail;
    }
    value &= 0b11001111;
    value |= (delay << 4);
    write_status = MPU6050_WriteReg8(MPU6050_REG_MOT_DETECT_CTRL, value);
    if (write_status != kStatus_I2C_Success){
    	return kStatus_I2C_Fail;
    } else {
    	return kStatus_I2C_Success;
    }
}

/*
uint8_t MPU6050_WriteRegisterBit(uint8_t reg, uint8_t pos, bool state)
{
    uint8_t value;
    uint8_t read_error_status;
    uint8_t write_error_status;

    read_error_status = MPU6050_ReadReg8(reg, &value);
    if(read_error_status != kStatus_I2C_Success){
    	return kStatus_I2C_Fail;
    }

    if (state)
    {
        value |= (1 << pos);
    } else
    {
        value &= ~(1 << pos);
    }

    write_error_status = MPU6050_WriteReg8(reg, value);
    if (write_error_status != kStatus_I2C_Success){
    	return kStatus_I2C_Fail;
    } else {
    	return kStatus_I2C_Success;
    }
}

*/


uint8_t MPU6050_WriteRegisterBit(uint8_t reg, uint8_t pos, uint8_t value)
{
    uint8_t buffer;
    uint8_t read_error_status;
    uint8_t write_error_status;

    read_error_status = MPU6050_ReadReg8(reg, &buffer);
    if(read_error_status != kStatus_I2C_Success){
    	return kStatus_I2C_Fail;
    }

    //buffer = (value != 0) ? (buffer | (1<<pos)) : (buffer &= ~(1<<pos));
    if (buffer)
    {
        buffer |= (1 << pos);
    } else
    {
        buffer &= ~(1 << pos);
    }

    write_error_status = MPU6050_WriteReg8(reg, buffer);
    if (write_error_status != kStatus_I2C_Success){
    	return kStatus_I2C_Fail;
    } else {
    	return kStatus_I2C_Success;
    }
}

/*
int8_t I2Cdev_writeBits(uint8_t dev_addr, uint8_t reg_addr, uint8_t start_bit,
		uint8_t len, uint8_t data)
{
    uint8_t b;
    int8_t err;

    if ((err = I2Cdev_readByte(dev_addr, reg_addr, &b)) == 0) {
        uint8_t mask = ((1 << len) - 1) << (start_bit - len + 1);
        data <<= (start_bit - len + 1); // shift data into correct position
        data &= mask; // zero all non-important bits in data
        b &= ~(mask); // zero all important bits in existing byte
        b |= data; // combine data with existing byte

        return I2Cdev_writeByte(dev_addr, reg_addr, b);
    }
    else {
        return err;
    }
}
*/

uint8_t MPU6050_WriteRegisterBits(uint8_t reg_addr, uint8_t start_bit, uint8_t len, uint8_t data)
{
    uint8_t b;
    int8_t err;
    err = MPU6050_ReadReg8(reg_addr, &b);
    if (err  == 0) {
        uint8_t mask = ((1 << len) - 1) << (start_bit - len + 1);
        data <<= (start_bit - len + 1); // shift data into correct position
        data &= mask; // zero all non-important bits in data
        b &= ~(mask); // zero all important bits in existing byte
        b |= data; // combine data with existing byte

        return MPU6050_WriteReg8(reg_addr, b);
    }
    else {
        return err;
    }
}

/*

int8_t 	I2Cdev_writeBit(uint8_t dev_addr, uint8_t reg_addr, uint8_t bit_n, uint8_t data) {
	uint8_t b;
	int8_t err;

	err = I2Cdev_readByte(dev_addr, reg_addr, &b);
	if(err < 0) {
		return err;
	}

	b = (data != 0) ? (b | (1<<bit_n)) : (b &= ~(1<<bit_n));

	return I2Cdev_writeByte(dev_addr, reg_addr, b);
}
*/

uint8_t MPU6050_SetDeviceReset(uint8_t value)
{
	uint8_t error_status;
	error_status = MPU6050_WriteRegisterBit(MPU6050_PWR_MGMT_1, 7, value);
	if (error_status != kStatus_I2C_Success) {
		return kStatus_I2C_Fail;
	} else {
		return kStatus_I2C_Success;
	}
}

uint8_t MPU6050_SetIntFreeFallEnabled(uint8_t value)
{
	uint8_t error_status;
	error_status = MPU6050_WriteRegisterBit(MPU6050_INTERRUPT_ENABLE, 7, value);
	if (error_status != kStatus_I2C_Success) {
		return kStatus_I2C_Fail;
	} else {
		return kStatus_I2C_Success;
	}
}

uint8_t MPU6050_SetIntZeroMotionEnabled(uint8_t value)
{
	uint8_t error_status;
	error_status = MPU6050_WriteRegisterBit(MPU6050_INTERRUPT_ENABLE, 5, value);
	if (error_status != kStatus_I2C_Success) {
		return kStatus_I2C_Fail;
	} else {
		return kStatus_I2C_Success;
	}
}

uint8_t MPU6050_SetIntMotionEnabled(uint8_t value)
{
	uint8_t error_status;
	error_status = MPU6050_WriteRegisterBit(MPU6050_INTERRUPT_ENABLE, 6, value);
	if (error_status != kStatus_I2C_Success) {
		return kStatus_I2C_Fail;
	} else {
		return kStatus_I2C_Success;
	}
}

uint8_t MPU6050_WhoAmI()
{
  static const uint8_t addr = MPU6050_WHO_AM_I;
  uint8_t value;
  uint8_t rt;

  rt = I2C_DRV_MasterReceiveDataBlocking( I2C1_IDX, &mpu6050_parameters, (uint8_t*)&addr, sizeof(addr), (uint8_t*)&value, sizeof(value), 20 );
  if(rt == kStatus_I2C_Success){
	  return value;
  } else {
	  return rt;
  }
}

uint8_t MPU6050_GetAccelXYZ(uint8_t* a_x, uint8_t* a_y, uint8_t* a_z)
{
	uint8_t x;
	uint8_t y;
	uint8_t z;

	do {
		if (MPU6050_ReadReg8( MPU6050_ACCEL_XOUT_H, &x ) != kStatus_I2C_Success)
			break;
		if (MPU6050_ReadReg8( MPU6050_ACCEL_YOUT_H, &y ) != kStatus_I2C_Success)
			break;
		if (MPU6050_ReadReg8( MPU6050_ACCEL_ZOUT_H, &z ) != kStatus_I2C_Success)
			break;
		*a_x = x;
		*a_y = y;
		*a_z = z;
		return kStatus_I2C_Success;
	} while (1);
	return kStatus_I2C_Fail;
}

uint8_t MPU6050_GetGyroXYZ(uint8_t* g_x, uint8_t* g_y, uint8_t* g_z)
{
	uint8_t x;
	uint8_t y;
	uint8_t z;

	do {
		if (MPU6050_ReadReg8( MPU6050_GYRO_XOUT_H, &x ) != kStatus_I2C_Success)
			break;
		if (MPU6050_ReadReg8( MPU6050_GYRO_YOUT_H, &y ) != kStatus_I2C_Success)
			break;
		if (MPU6050_ReadReg8( MPU6050_GYRO_ZOUT_H, &z ) != kStatus_I2C_Success)
			break;
		*g_x = x;
		*g_y = y;
		*g_z = z;
		return kStatus_I2C_Success;
	} while (1);
	return kStatus_I2C_Fail;
}


uint8_t MPU6050_GetTemperature()
{
	uint8_t buffer[2];
	int16_t temp;
    memset(buffer, 0, sizeof(buffer));
    if (MPU6050_ReadReg8( MPU6050_TEMP_OUT_H, buffer) == kStatus_I2C_Success){
    	temp = (((int16_t)buffer[0]) << 8) | buffer[1];
  	    temp = 36.53 + temp / 340;
  		return temp;
    } else {
    	return kStatus_I2C_Fail;
    }
}

uint8_t MPU6050_GetFreeFallDetectionThreshold(uint8_t* threshold) {

	if (MPU6050_ReadReg8( MPU6050_FF_THR, threshold ) != kStatus_I2C_Success){
		return kStatus_I2C_Fail;
	} else {
		return kStatus_I2C_Success;
	}
}

/** Get free-fall event duration threshold.
 * This register configures the duration counter threshold for Free Fall event
 * detection. The duration counter ticks at 1kHz, therefore FF_DUR has a unit
 * of 1 LSB = 1 ms.
 *
 * The Free Fall duration counter increments while the absolute value of the
 * accelerometer measurements are each less than the detection threshold
 * (Register 29). The Free Fall interrupt is triggered when the Free Fall
 * duration counter reaches the time specified in this register.
 *
 * For more details on the Free Fall detection interrupt, see Section 8.2 of
 * the MPU-6000/MPU-6050 Product Specification document as well as Registers 56
 * and 58 of this document.
 *
 * @return Current free-fall duration threshold value (LSB = 1ms)
 * @see FF_DUR
 */

uint8_t MPU6050_SetFreeFallDetectionThreshold(uint8_t threshold)
{
    if (MPU6050_WriteReg8(MPU6050_FF_THR, threshold) != kStatus_I2C_Success) {
    	return kStatus_I2C_Fail;
    } else {
    	return kStatus_I2C_Success;
    }
}

uint8_t MPU6050_GetFreeFallDetectionDuration(uint8_t* duration)
{
    if (MPU6050_ReadReg8(MPU6050_FF_DUR, duration) != kStatus_I2C_Success) {
    	return kStatus_I2C_Fail;
    } else {
    	return kStatus_I2C_Success;
    }
}

uint8_t MPU6050_SetFreeFallDetectionDuration(uint8_t duration)
{
	if (MPU6050_WriteReg8(MPU6050_FF_DUR, duration) != kStatus_I2C_Success){
		return kStatus_I2C_Fail;
	} else {
		return kStatus_I2C_Success;
	}
}

/*
void MPU6050::setDHPFMode(mpu6050_dhpf_t dhpf)
{
    uint8_t value;
    value = readRegister8(MPU6050_REG_ACCEL_CONFIG);
    value &= 0b11111000;
    value |= dhpf;
    writeRegister8(MPU6050_REG_ACCEL_CONFIG, value);
}
*/
/*

void MPU6050_setDHPFMode(uint8_t bandwidth) {
    I2Cdev_writeBits(mpu6050.devAddr, MPU6050_RA_ACCEL_CONFIG, MPU6050_ACONFIG_ACCEL_HPF_BIT, MPU6050_ACONFIG_ACCEL_HPF_LENGTH, bandwidth);
}
*/


uint8_t MPU6050_SetDHPFMode(mpu6050_dhpf_t dhpf)
{
	uint8_t read_status;
	uint8_t write_status;
	uint8_t value;
	read_status = MPU6050_ReadReg8(MPU6050_ACCEL_CONFIG, &value);
    if (read_status != kStatus_I2C_Success) {
    	return kStatus_I2C_Fail;
    }
    value &= 0b11111000;
    value |= dhpf;
    write_status = MPU6050_WriteRegisterBits(MPU6050_ACCEL_CONFIG, MPU6050_ACONFIG_ACCEL_HPF_BIT, MPU6050_ACONFIG_ACCEL_HPF_LENGTH, value) != kStatus_I2C_Success;
	if (write_status){
		return kStatus_I2C_Fail;
	} else {
		return kStatus_I2C_Success;
	}
}

uint8_t MPU6050_ReadActivites(uint8_t* is_free_fall)
{
	uint8_t read_status;
    uint8_t data;
    uint8_t ff;
    read_status = MPU6050_ReadReg8(MPU6050_REG_INT_STATUS, &data);
    if (read_status  != kStatus_I2C_Success) {
    	return kStatus_I2C_Fail;
    } else {
        ff = ((data >> 7) & 1);
        *is_free_fall = ff;
        return kStatus_I2C_Success;
    }
}

uint8_t init_example(){
	uint8_t temporario = 1;
	return temporario;
}
