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

#include "nRF24L01_API.h"

extern msg_queue_handler_t temperature_msg_queue_handler;
extern semaphore_t radioIRQ_semaphore;

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
	OSA_TimeDelay(1000); /* Example code (for task release) */

	return RADIO_PRONTO;
}

static RADIO_RETORNO TRANSMITE_AMOSTRAS_PORT(void) {
	uint8_t radio_status = 0;

	if( OSA_MsgQGet( temperature_msg_queue_handler, &valorATransmitir, 2000 ) != kStatus_OSA_Success ) {
		debug_printf("No data to send!\n\r");
		return RADIO_FALHA_TRANSMISSAO;
	}

#if DEBUG
	debug_printf("%5.2f Celsius Degree: ", valorATransmitir );
#endif

	if( nRF24L01_transmitPayload( &transmitSetup ) != NRF24L01_STATE_SUCCESS )
		return RADIO_FALHA_TRANSMISSAO;

	if( OSA_SemaWait( radioIRQ_semaphore, 1000 ) != kStatus_OSA_Success )
		return RADIO_FALHA_TRANSMISSAO;

	radio_status = nRF24L01_readStatus();

	if( radio_status & NRF24L01_MAX_RT ) {
		L01_Clear_IRQ( NRF24L01_MAX_RT );
#if DEBUG
		debug_printf("Transmission failed!\n\r");
#endif
		return RADIO_FALHA_TRANSMISSAO;
	}

	if( radio_status & NRF24L01_TX_DS ) {
		L01_Clear_IRQ( NRF24L01_TX_DS );
#if DEBUG
		debug_printf("Transmission succeed!\n\r");
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
