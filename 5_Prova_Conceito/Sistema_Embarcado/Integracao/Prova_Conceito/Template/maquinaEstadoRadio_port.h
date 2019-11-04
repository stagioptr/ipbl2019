/*
 ******************************************************************************
 * @file    maquinaEstadoRadio_port.h
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    10-Outubro-2019
 * @brief   Máquina de estados para tratamento do radio nRF24L01.
 ******************************************************************************
 */

#include "stdint.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

extern QueueHandle_t sensor_x_msg_queue_handler;

#define		RADIO_RETORNO									uint32_t

#define 	RADIO_PRONTO										0
#define 	CONFIGURACAO_OK									1
#define 	FALHA_CONFIGURACAO							2
#define		FALHA_CONEXAO										3
#define		PERIFERICO_OK										4
#define		CONECTADO												5
#define		SUCESSO_TRANSMISSAO							6
#define		FALHA_TRANSMISSAO								7
#define		FALHA_RECUPERAVEL								8
#define		FALHA_PERMANENTE								9
#define		DESCONFIGURACAO_OK							10
#define		FALHA_DESCONFIGURACAO						11

RADIO_RETORNO CONFIGURA_RADIO_PORT(void) {
	return CONFIGURACAO_OK;
}

RADIO_RETORNO CONECTAR_PORT(void) {
	return CONECTADO;
}

RADIO_RETORNO AGUARDA_TEMPO_TRANSMISSAO_PORT(void) {
	OSA_TimeDelay(1000); /* Example code (for task release) */

	return RADIO_PRONTO;
}

RADIO_RETORNO TRANSMITE_AMOSTRAS_PORT(void) {
	uint32_t valorATransmitir = 0;

	if( xQueueReceive( sensor_x_msg_queue_handler, &valorATransmitir, pdMS_TO_TICKS(1000) ) == pdPASS )
		return SUCESSO_TRANSMISSAO;
	else
		return FALHA_TRANSMISSAO;
}

RADIO_RETORNO VERIFICA_TIPO_FALHA_PORT(void) {
	return FALHA_RECUPERAVEL;
}

RADIO_RETORNO DESCONFIGURA_RADIO_PORT(void) {
	return DESCONFIGURACAO_OK;
}
