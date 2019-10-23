/*
 ******************************************************************************
 * @file    maquinaEstadoRadio.c
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    10-Outubro-2019
 * @brief   Máquina de estados para tratamento do radio nRF24L01.
 ******************************************************************************
 */

#include "maquinaEstadoRadio_port.h"
#include "maquinaEstadoRadio.h"

/*
 * Definição dos estados da máquina.
 */
typedef enum {
	CONFIGURA_RADIO = 0,
	CONECTAR,
	AGUARDA_TEMPO_TRANSMISSAO,
	TRANSMITE_AMOSTRAS,
	VERIFICA_TIPO_FALHA,
	DESCONFIGURA_RADIO,
	ENCERRA_ROTINA
} radio_EstadosEnum_t;

/*
 * Controle do estado atual da máquina.
 */
static radio_EstadosEnum_t estadoMaquina = CONFIGURA_RADIO;
static RADIO_RETORNO estadoRadio = RADIO_PRONTO;

/*
 * Rotina para execução da máquina de estados, conforme diagrama do Modelio - localizado na pasta documentos.
 */
void radio_stateMachine(void) {
	while (1) {
		switch (estadoMaquina) {
		case CONFIGURA_RADIO:

			estadoRadio = CONFIGURA_RADIO_PORT();

			if (estadoRadio == CONFIGURACAO_OK)
				estadoMaquina = CONECTAR;
			else if (estadoRadio == FALHA_CONFIGURACAO)
				estadoMaquina = VERIFICA_TIPO_FALHA;

			break;

		case CONECTAR:
			estadoRadio = CONECTAR_PORT();

			if (estadoRadio == FALHA_CONEXAO)
				estadoMaquina = VERIFICA_TIPO_FALHA;
			else if (estadoRadio == CONECTADO)
				estadoMaquina = AGUARDA_TEMPO_TRANSMISSAO;
			else if (estadoRadio == PERIFERICO_OK)
				estadoMaquina = CONECTAR;

			break;

		case AGUARDA_TEMPO_TRANSMISSAO:
			estadoRadio = AGUARDA_TEMPO_TRANSMISSAO_PORT();

			estadoMaquina = TRANSMITE_AMOSTRAS;

			break;

		case TRANSMITE_AMOSTRAS:
			estadoRadio = TRANSMITE_AMOSTRAS_PORT();

			if (estadoRadio == SUCESSO_TRANSMISSAO)
				estadoMaquina = AGUARDA_TEMPO_TRANSMISSAO;
			else if (estadoRadio == FALHA_TRANSMISSAO)
				estadoMaquina = VERIFICA_TIPO_FALHA;

			break;

		case VERIFICA_TIPO_FALHA:
			estadoRadio = VERIFICA_TIPO_FALHA_PORT();

			if (estadoRadio == FALHA_RECUPERAVEL)
				estadoMaquina = DESCONFIGURA_RADIO;
			else if (estadoRadio == FALHA_PERMANENTE)
				estadoMaquina = ENCERRA_ROTINA;

			break;

		default:
		case DESCONFIGURA_RADIO:
			estadoRadio = DESCONFIGURA_RADIO_PORT();

			if (estadoRadio == DESCONFIGURACAO_OK)
				estadoMaquina = CONFIGURA_RADIO;
			else if (estadoRadio == FALHA_DESCONFIGURACAO)
				estadoMaquina = ENCERRA_ROTINA;

			break;

		case ENCERRA_ROTINA:
			return;

		}
	}
}
