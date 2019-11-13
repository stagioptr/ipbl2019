/*
 ******************************************************************************
 * @file    maquinaEstadoRadio_port.h
 * @author  V�tor Eduardo Sabadine da Cruz
 * @version 0
 * @date    10-Outubro-2019
 * @brief   M�quina de estados para tratamento do radio nRF24L01.
 ******************************************************************************
 */

#include "stdint.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#include "nRF24L01_API.h"

#include "shellStateMachine.h"

extern QueueHandle_t temperature_msg_queue_handler;
extern semaphore_t nRF24L01_Radio_IRQ;

#if defined DEBUG
	extern QueueHandle_t radio_debug_msg_queue_handler;
#endif

typedef enum {
	RADIO_PRONTO,
	RADIO_CONFIGURACAO_OK,
	RADIO_FALHA_CONFIGURACAO,
	RADIO_FALHA_CONEXAO,
	RADIO_PERIFERICO_OK,
	RADIO_CONECTADO,
	RADIO_SUCESSO_TRANSMISSAO,
	RADIO_FALHA_TRANSMISSAO,
	RADIO_FALHA_RECUPERAVEL,
	RADIO_FALHA_PERMANENTE,
	RADIO_DESCONFIGURACAO_OK,
	RADIO_FALHA_DESCONFIGURACAO,
}RADIO_RETORNO;

float valorATransmitir = 0;

static NRF24L01_transferSetupStruct_t transmitSetup = {
		.payload = (uint8_t*)&valorATransmitir,
		.payloadWidth = sizeof(float),
		.address = { 0x10, 0x20, 0x30, 0x40, 0x01 },
		.addressLength = 5
};



static RADIO_RETORNO CONFIGURA_RADIO_PORT(void) {
	if( nRF24L01_Init() != NRF24L01_STATE_SUCCESS )
		return RADIO_FALHA_CONFIGURACAO;

	return RADIO_CONFIGURACAO_OK;
}

static RADIO_RETORNO CONECTAR_PORT(void) {
	return RADIO_CONECTADO;
}

static RADIO_RETORNO AGUARDA_TEMPO_TRANSMISSAO_PORT(void) {
	OSA_TimeDelay(250); /* Example code (for task release) */

	return RADIO_PRONTO;
}

static RADIO_RETORNO TRANSMITE_AMOSTRAS_PORT(void) {
	uint8_t radio_status = 0;

	if( xQueueReceive( temperature_msg_queue_handler, &valorATransmitir, pdMS_TO_TICKS(1000) ) == pdFAIL ) {
#if DEBUG
		radioDebugCodeEnum_t temp = SHELL_DEBUG_RADIO_EVENT_MISSING_DATA;

		xQueueSendToBack(radio_debug_msg_queue_handler,&temp,0);
#endif
		return RADIO_FALHA_TRANSMISSAO;
	}

#if DEBUG
//	debug_printf("%5.2f Celsius Degree: ", valorATransmitir );
#endif

	if( nRF24L01_transmitPayload( &transmitSetup ) != NRF24L01_STATE_SUCCESS )
		return RADIO_FALHA_TRANSMISSAO;

	if( xSemaphoreTake( nRF24L01_Radio_IRQ, pdMS_TO_TICKS(1000) ) == pdFALSE )
		return RADIO_FALHA_TRANSMISSAO;

	radio_status = nRF24L01_readStatus();

	if( radio_status & NRF24L01_MAX_RT ) {
		L01_Clear_IRQ( NRF24L01_MAX_RT );
#if DEBUG
//		debug_printf("Transmition failed!\n\r");
		radioDebugCodeEnum_t temp = SHELL_DEBUG_RADIO_EVENT_SEND_NO_ACK;

		xQueueSendToBack(radio_debug_msg_queue_handler,&temp,0);
#endif
		return RADIO_FALHA_TRANSMISSAO;
	}

	if( radio_status & NRF24L01_TX_DS ) {
		L01_Clear_IRQ( NRF24L01_TX_DS );
#if DEBUG
//		debug_printf("Transmition succeed!\n\r");
		radioDebugCodeEnum_t temp = SHELL_DEBUG_RADIO_EVENT_SEND_OK;

		xQueueSendToBack(radio_debug_msg_queue_handler,&temp,0);
#endif
		return RADIO_SUCESSO_TRANSMISSAO;
	}

	if( radio_status & NRF24L01_RX_DR ) {
		L01_Clear_IRQ( NRF24L01_RX_DR );
	}

	return RADIO_FALHA_TRANSMISSAO;
}

static RADIO_RETORNO VERIFICA_TIPO_FALHA_PORT(void) {
	return RADIO_FALHA_RECUPERAVEL;
}

static RADIO_RETORNO DESCONFIGURA_RADIO_PORT(void) {
	return RADIO_DESCONFIGURACAO_OK;
}
