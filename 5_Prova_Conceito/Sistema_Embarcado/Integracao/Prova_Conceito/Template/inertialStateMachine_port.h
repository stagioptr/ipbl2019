/*
 ******************************************************************************
 * @file    maquinaEstadoSensor_port.h
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    10-Outubro-2019
 * @brief   Máquina de estados para tratamento de sensor genérico.
 ******************************************************************************
 */

#include "stdint.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#include "mpu6050.h"

extern msg_queue_handler_t inertial_msg_queue_handler;
extern msg_queue_handler_t freeFall_msg_queue_handler;

struct {
	float accelerometerX;
	float accelerometerY;
	float accelerometerZ;
	float gyroX;
	float gyroY;
	float gyroZ;
} inertialData = {
	.accelerometerX = 0.0,
	.accelerometerY = 0.0,
	.accelerometerZ = 0.0,
	.gyroX = 0.0,
	.gyroY = 0.0,
	.gyroZ = 0.0
}, inertialReference = {
	.accelerometerX = 0.0,
	.accelerometerY = 0.0,
	.accelerometerZ = 0.0,
	.gyroX = 0.0,
	.gyroY = 0.0,
	.gyroZ = 0.0
};

uint32_t freeFallStatus = 0;

bool referenceCaptured = false;

typedef enum {
	SENSOR_READY,
	SENSOR_INIT_OK,
	SENSOR_INIT_FAIL,
	SENSOR_TIME_OUT,
	SENSOR_SAMPLE_READY,
	SENSOR_FAIL,
	SENSOR_SAMPLE_OK,
	SENSOR_DATA_VALIDATED,
	SENSOR_DATA_INVALIDATED,
	SENSOR_RECOVERABLE_FAIL,
	SENSOR_PERMANENT_FAIL,
	SENSOR_DEINIT_OK,
	SENSOR_DEINIT_FAIL,
}INERTIA_RETURN;

static INERTIA_RETURN INERTIA_INIT_PORT(void) {
	do {

		if( MPU6050_Init() != kStatus_I2C_Success )
			break;

		if( MPU6050_SetAccelPowerOnDelay(MPU6050_DELAY_3MS) != kStatus_I2C_Success )
			break;

		//Int Free Fall
		if( MPU6050_SetIntFreeFallEnabled(1) != kStatus_I2C_Success )
			break;

		//Int Zero Motion
		if( MPU6050_SetIntZeroMotionEnabled(0) != kStatus_I2C_Success )
			break;

		//Int Motion
		if( MPU6050_SetIntMotionEnabled(0) != kStatus_I2C_Success )
			break;

		//Set high-pass filter
		if( MPU6050_SetDHPFMode(MPU6050_DHPF_5HZ) != kStatus_I2C_Success )
			break;

		//Set Free Fall threshold
		if( MPU6050_SetFreeFallDetectionThreshold(100) != kStatus_I2C_Success )
			break;

		//Set duration
		if( MPU6050_SetFreeFallDetectionDuration(25) != kStatus_I2C_Success )
			break;

		return SENSOR_INIT_OK;
	} while(0);
	return SENSOR_INIT_FAIL;
}

static INERTIA_RETURN INERTIA_WAITING_FOR_DATA_PORT(void) {
	OSA_TimeDelay(1000); /* Wait conversion time */

	return SENSOR_SAMPLE_READY;
}

static INERTIA_RETURN INERTIA_READING_DATA_PORT(void) {
	int8_t dataAccelerometerX = 0;
	int8_t dataAccelerometerY = 0;
	int8_t dataAccelerometerZ = 0;
	int8_t dataGyroX = 0;
	int8_t dataGyroY = 0;
	int8_t dataGyroZ = 0;
	uint8_t freeFallStatusTemp = 0;

	MPU6050_ReadActivites(&freeFallStatusTemp);

	freeFallStatus = freeFallStatusTemp;

	MPU6050_GetAccelXYZ( &dataAccelerometerX, &dataAccelerometerY, &dataAccelerometerZ );
	MPU6050_GetGyroXYZ( &dataGyroX, &dataGyroY, &dataGyroZ );

	if( referenceCaptured )
	{
		inertialData.accelerometerX = ((float)(dataAccelerometerX))/8.0 - inertialReference.accelerometerX;
		inertialData.accelerometerY = ((float)(dataAccelerometerY))/8.0 - inertialReference.accelerometerY;
		inertialData.accelerometerZ = ((float)(dataAccelerometerZ))/8.0 - inertialReference.accelerometerZ;

		inertialData.gyroX = ((float)(dataGyroX))/0.512 - inertialReference.gyroX;
		inertialData.gyroY = ((float)(dataGyroY))/0.512 - inertialReference.gyroY;
		inertialData.gyroZ = ((float)(dataGyroZ))/0.512 - inertialReference.gyroZ;
	}
	else {
		inertialReference.accelerometerX = ((float)(dataAccelerometerX))/8.0;
		inertialReference.accelerometerY = ((float)(dataAccelerometerY))/8.0;
		inertialReference.accelerometerZ = ((float)(dataAccelerometerZ))/8.0;

		inertialReference.gyroX = ((float)(dataGyroX))/0.512;
		inertialReference.gyroY = ((float)(dataGyroY))/0.512;
		inertialReference.gyroZ = ((float)(dataGyroZ))/0.512;

		referenceCaptured = true;
	}

	return SENSOR_SAMPLE_OK;
}

static INERTIA_RETURN INERTIA_COMPUTING_DATA_PORT(void) {
	if( OSA_MsgQPut(inertial_msg_queue_handler, &inertialData ) != kStatus_OSA_Success )
		return SENSOR_DATA_INVALIDATED;

	if( OSA_MsgQPut(freeFall_msg_queue_handler, &freeFallStatus ) != kStatus_OSA_Success )
			return SENSOR_DATA_INVALIDATED;

	return SENSOR_DATA_VALIDATED;
}

static INERTIA_RETURN VERIFICA_TIPO_FALHA_PORT(void) {
	return SENSOR_RECOVERABLE_FAIL;
}

static INERTIA_RETURN INERTIA_DEINIT_PORT(void) {
	return SENSOR_DEINIT_OK;
}
