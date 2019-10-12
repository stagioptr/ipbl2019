/*
 ******************************************************************************
 * @file    maquinaEstadoSensor.c
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    10-Outubro-2019
 * @brief   Máquina de estados para tratamento de sensor genérico.
 ******************************************************************************
 */

#include "maquinaEstadoSensor_port.h"
#include "maquinaEstadoSensor.h"

/*
 * Definição dos estados da máquina.
 */
typedef enum {
	CONFIGURA_SENSOR = 0,
	AGUARDA_DADOS,
	LER_DADOS,
	INTERPRETA_DADOS,
	VERIFICA_TIPO_FALHA,
	DESCONFIGURA_SENSOR,
	ENCERRA_ROTINA
} sensor_EstadosEnum_t;

/*
 * Controle do estado atual da máquina.
 */
static sensor_EstadosEnum_t estadoMaquina = CONFIGURA_SENSOR;
static SENSOR_RETORNO estadoSensor = SENSOR_PRONTO;

/*
 * Rotina para execução da máquina de estados, conforme diagrama do Modelio - localizado na pasta documentos.
 */
void sensor_stateMachine(void) {
	while (1) {
		switch (estadoMaquina) {
		case CONFIGURA_SENSOR:

			estadoSensor = CONFIGURA_SENSOR_PORT();

			if (estadoSensor == CONFIGURACAO_OK)
				estadoMaquina = AGUARDA_DADOS;
			else if (estadoSensor == FALHA_CONFIGURACAO)
				estadoMaquina = VERIFICA_TIPO_FALHA;

			break;

		case AGUARDA_DADOS:
			estadoSensor = AGUARDA_DADOS_PORT();

			if (estadoSensor == TEMPO_ESGOTADO)
				estadoMaquina = VERIFICA_TIPO_FALHA;
			else if (estadoSensor == AMOSTRA_PRONTA)
				estadoMaquina = LER_DADOS;

			break;

		case LER_DADOS:
			estadoSensor = LER_DADOS_PORT();

			if (estadoSensor == FALHA_SENSOR)
				estadoMaquina = VERIFICA_TIPO_FALHA;
			else if (estadoSensor == AMOSTRA_OK)
				estadoMaquina = INTERPRETA_DADOS;

			break;

		case INTERPRETA_DADOS:
			estadoSensor = INTERPRETA_DADOS_PORT();

			if (estadoSensor == DADOS_VALIDOS)
				estadoMaquina = AGUARDA_DADOS;
			else if (estadoSensor == DADOS_INVALIDOS)
				estadoMaquina = VERIFICA_TIPO_FALHA;

			break;

		case VERIFICA_TIPO_FALHA:
			estadoSensor = VERIFICA_TIPO_FALHA_PORT();

			if (estadoSensor == FALHA_RECUPERAVEL)
				estadoMaquina = DESCONFIGURA_SENSOR;
			else if (estadoSensor == FALHA_PERMANENTE)
				estadoMaquina = ENCERRA_ROTINA;

			break;

		default:
		case DESCONFIGURA_SENSOR:
			estadoSensor = DESCONFIGURA_SENSOR_PORT();

			if (estadoSensor == DESCONFIGURACAO_OK)
				estadoMaquina = CONFIGURA_SENSOR;
			else if (estadoSensor == FALHA_DESCONFIGURACAO)
				estadoMaquina = ENCERRA_ROTINA;

			break;

		case ENCERRA_ROTINA:
			return;

		}
	}
}
