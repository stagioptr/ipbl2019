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

#include "MAX6675_API.h"

extern QueueHandle_t temperature_msg_queue_handler;
float temperatureCelsiusDegree = 0.0;

typedef enum {
	SENSOR_PRONTO,
	SENSOR_CONFIGURACAO_OK,
	SENSOR_FALHA_CONFIGURACAO,
	SENSOR_TEMPO_ESGOTADO,
	SENSOR_AMOSTRA_PRONTA,
	SENSOR_FALHA_SENSOR,
	SENSOR_AMOSTRA_OK,
	SENSOR_DADOS_VALIDOS,
	SENSOR_DADOS_INVALIDOS,
	SENSOR_FALHA_RECUPERAVEL,
	SENSOR_FALHA_PERMANENTE,
	SENSOR_DESCONFIGURACAO_OK,
	SENSOR_FALHA_DESCONFIGURACAO,
}SENSOR_RETORNO;

static SENSOR_RETORNO CONFIGURA_SENSOR_PORT(void) {
	if( MAX6675_Init() != MAX6675_STATE_SUCCESS )
		return SENSOR_FALHA_CONFIGURACAO;
	else
		return SENSOR_CONFIGURACAO_OK;
}

static SENSOR_RETORNO AGUARDA_DADOS_PORT(void) {
	OSA_TimeDelay(250); /* Wait conversion time */

	return SENSOR_AMOSTRA_PRONTA;
}

static SENSOR_RETORNO LER_DADOS_PORT(void) {
	uint16_t max6675Value;

	if( MAX6675_readValue( &max6675Value ) )
		return SENSOR_FALHA_SENSOR;

	temperatureCelsiusDegree = MAX6675_convertValueToCelsiusDegree( max6675Value );

	return SENSOR_AMOSTRA_OK;
}

static SENSOR_RETORNO INTERPRETA_DADOS_PORT(void) {
	// Código do SCADE aqui.
	if( xQueueSendToBack( temperature_msg_queue_handler, &temperatureCelsiusDegree, 0 ) == pdPASS )
		return SENSOR_DADOS_VALIDOS;
	else
		return SENSOR_DADOS_INVALIDOS;
}

static SENSOR_RETORNO VERIFICA_TIPO_FALHA_PORT(void) {
	return SENSOR_FALHA_RECUPERAVEL;
}

static SENSOR_RETORNO DESCONFIGURA_SENSOR_PORT(void) {
	return SENSOR_DESCONFIGURACAO_OK;
}
