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
	CONFIGURANDO_RADIO = 0,
	CONECTANDO,
	AGUARDANDO_TEMPO_TRANSMISSAO,
	TRANSMITINDO_AMOSTRAS,
	DESCONFIGURANDO_RADIO,
	VERIFICANDO_TIPO_FALHA,
	ENCERRANDO_ROTINA
} radio_EstadosEnum_t;

/*
 * Controle do estado atual da máquina.
 */
static radio_EstadosEnum_t estadoMaquina = CONFIGURANDO_RADIO;
static RADIO_RETORNO estadoRadio = RADIO_PRONTO;

/*
 * Rotina para execução da máquina de estados, conforme diagrama do Modelio - localizado na pasta documentos.
 */
void radio_stateMachine(void) {
	while (1) {
		switch (estadoMaquina) {
		case CONFIGURANDO_RADIO:

			estadoRadio = CONFIGURA_RADIO_PORT();

			if (estadoRadio == RADIO_CONFIGURACAO_OK)
				estadoMaquina = CONECTANDO;
			else if (estadoRadio == RADIO_FALHA_CONFIGURACAO)
				estadoMaquina = DESCONFIGURANDO_RADIO;

			break;

		case CONECTANDO:
			estadoRadio = CONECTAR_PORT();

			if (estadoRadio == RADIO_FALHA_CONEXAO)
				estadoMaquina = DESCONFIGURANDO_RADIO;
			else if (estadoRadio == RADIO_CONECTADO)
				estadoMaquina = AGUARDANDO_TEMPO_TRANSMISSAO;
			else if (estadoRadio == RADIO_PERIFERICO_OK)
				estadoMaquina = CONECTANDO;

			break;

		case AGUARDANDO_TEMPO_TRANSMISSAO:
			estadoRadio = AGUARDA_TEMPO_TRANSMISSAO_PORT();

			estadoMaquina = TRANSMITINDO_AMOSTRAS;

			break;

		case TRANSMITINDO_AMOSTRAS:
			estadoRadio = TRANSMITE_AMOSTRAS_PORT();

			if (estadoRadio == RADIO_SUCESSO_TRANSMISSAO)
				estadoMaquina = AGUARDANDO_TEMPO_TRANSMISSAO;
			else if (estadoRadio == RADIO_FALHA_TRANSMISSAO)
				estadoMaquina = DESCONFIGURANDO_RADIO;

			break;

		default:
		case DESCONFIGURANDO_RADIO:
			estadoRadio = DESCONFIGURA_RADIO_PORT();

			if (estadoRadio == RADIO_DESCONFIGURACAO_OK)
				estadoMaquina = VERIFICANDO_TIPO_FALHA;
			else if (estadoRadio == RADIO_FALHA_DESCONFIGURACAO)
				estadoMaquina = ENCERRANDO_ROTINA;

			break;

		case VERIFICANDO_TIPO_FALHA:
/*			estadoRadio = VERIFICA_TIPO_FALHA_PORT();

			if (estadoRadio == RADIO_FALHA_RECUPERAVEL)
				estadoMaquina = CONFIGURANDO_RADIO;
			else if (estadoRadio == RADIO_FALHA_PERMANENTE)
				estadoMaquina = ENCERRANDO_ROTINA;*/
			estadoMaquina = CONECTANDO;

			break;

		case ENCERRANDO_ROTINA:
			return;

		}
	}
}
