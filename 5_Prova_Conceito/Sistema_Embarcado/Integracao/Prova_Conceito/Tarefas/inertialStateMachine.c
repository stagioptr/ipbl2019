/*
 ******************************************************************************
 * @file    inertialStateMachine.c
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    26-Novembro-2019
 * @brief   State machine for read inertia sensors.
 ******************************************************************************
 */

#include "inertialStateMachine_port.h"
#include "inertialStateMachine.h"

/*
 * Definição dos estados da máquina.
 */
typedef enum {
	INERTIA_INIT = 0,
	INERTIA_WAITING_FOR_DATA,
	INERTIA_READING_DATA,
	INERTIA_COMPUTING_DATA,
	INERTIA_DEINIT,
	INERTIA_FAILED,
	INERTIA_END_ROUTINE
} inertiaState_e;

/*
 * Rotina para execução da máquina de estados, conforme diagrama do Modelio - localizado na pasta documentos.
 */
void inertiaSensorStateMachine(void) {
/*
 * Controle do estado atual da máquina.
 */
	static inertiaState_e machineState = INERTIA_INIT;
	static INERTIA_RETURN sensorState = SENSOR_READY;

	while (1) {
		switch (machineState) {
		case INERTIA_INIT:

			sensorState = INERTIA_INIT_PORT();

			if (sensorState == SENSOR_INIT_OK)
				machineState = INERTIA_WAITING_FOR_DATA;
			else if (sensorState == SENSOR_INIT_FAIL)
				machineState = INERTIA_DEINIT;

			break;

		case INERTIA_WAITING_FOR_DATA:
			sensorState = INERTIA_WAITING_FOR_DATA_PORT();

			if (sensorState == SENSOR_TIME_OUT)
				machineState = INERTIA_DEINIT;
			else if (sensorState == SENSOR_SAMPLE_READY)
				machineState = INERTIA_READING_DATA;

			break;

		case INERTIA_READING_DATA:
			sensorState = INERTIA_READING_DATA_PORT();

			if (sensorState == SENSOR_FAIL)
				machineState = INERTIA_DEINIT;
			else if (sensorState == SENSOR_SAMPLE_OK)
				machineState = INERTIA_COMPUTING_DATA;

			break;

		case INERTIA_COMPUTING_DATA:
			sensorState = INERTIA_COMPUTING_DATA_PORT();

			if (sensorState == SENSOR_DATA_VALIDATED)
				machineState = INERTIA_WAITING_FOR_DATA;
			else if (sensorState == SENSOR_DATA_INVALIDATED)
				machineState = INERTIA_DEINIT;

			break;

		default:
		case INERTIA_DEINIT:
			sensorState = INERTIA_DEINIT_PORT();

			if (sensorState == SENSOR_DEINIT_OK)
				machineState = INERTIA_FAILED;
			else if (sensorState == SENSOR_DEINIT_FAIL)
				machineState = INERTIA_END_ROUTINE;

			break;

		case INERTIA_FAILED:
/*			sensorState = VERIFICA_TIPO_FALHA_PORT();

			if (sensorState == SENSOR_RECOVERABLE_FAIL)
				machineState = INERTIA_INIT;
			else if (sensorState == SENSOR_PERMANENT_FAIL)
				machineState = INERTIA_END_ROUTINE;*/

			machineState = INERTIA_WAITING_FOR_DATA;

			break;

		case INERTIA_END_ROUTINE:
			return;

		}
	}
}
