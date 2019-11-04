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

QueueHandle_t sensor_x_msg_queue_handler = NULL;

#define		SENSOR_RETORNO									uint32_t

#define 	SENSOR_PRONTO										0
#define 	CONFIGURACAO_OK									1
#define 	FALHA_CONFIGURACAO							2
#define		TEMPO_ESGOTADO									3
#define		AMOSTRA_PRONTA									4
#define		FALHA_SENSOR										5
#define		AMOSTRA_OK											6
#define		DADOS_VALIDOS										7
#define		DADOS_INVALIDOS									8
#define		FALHA_RECUPERAVEL								9
#define		FALHA_PERMANENTE								10
#define		DESCONFIGURACAO_OK							11
#define		FALHA_DESCONFIGURACAO						12

SENSOR_RETORNO CONFIGURA_SENSOR_PORT(void) {
	sensor_x_msg_queue_handler = xQueueCreate( 5, sizeof(uint32_t) );

	return CONFIGURACAO_OK;
}

SENSOR_RETORNO AGUARDA_DADOS_PORT(void) {
	OSA_TimeDelay(1000); /* Example code (for task release) */

	return AMOSTRA_PRONTA;
}

SENSOR_RETORNO LER_DADOS_PORT(void) {
	return AMOSTRA_OK;
}

SENSOR_RETORNO INTERPRETA_DADOS_PORT(void) {
	uint32_t valorSensor = 2374;

	if( xQueueSendToBack( sensor_x_msg_queue_handler, &valorSensor, 0 ) == pdPASS )
		return DADOS_VALIDOS;
	else
		return DADOS_INVALIDOS;
}

SENSOR_RETORNO VERIFICA_TIPO_FALHA_PORT(void) {
	return FALHA_RECUPERAVEL;
}

SENSOR_RETORNO DESCONFIGURA_SENSOR_PORT(void) {
	return DESCONFIGURACAO_OK;
}
