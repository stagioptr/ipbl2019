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
	DESCONFIGURA_SENSOR
} sensor_EstadosEnum_t;

/*
 * Controle do estado atual da máquina.
 */
static sensor_EstadosEnum_t estadoMaquina = 0;

/*
 * Rotina para execução da máquina de estados, conforme diagrama do Modelio - localizado na pasta documentos.
 */
void sensor_stateMachine(void) {
	switch (estadoMaquina) {
	case CONFIGURA_SENSOR: {
		SENSOR_RETORNO estadoSensor;

		estadoSensor = CONFIGURA_SENSOR_PORT();

		if (estadoSensor == CONFIGURACAO_OK)
			estadoMaquina = LER_DADOS;
		else if (estadoSensor == FALHA_CONFIGURACAO)
			estadoMaquina = VERIFICA_TIPO_FALHA;

	}
		break;

	case AGUARDA_DADOS:

		break;

	case LER_DADOS:
		break;

	case INTERPRETA_DADOS:
		break;

	case VERIFICA_TIPO_FALHA:
		break;

	default:
	case DESCONFIGURA_SENSOR:
		break;

	}
}
