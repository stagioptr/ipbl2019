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
	return CONFIGURACAO_OK;
}

SENSOR_RETORNO AGUARDA_DADOS_PORT(void) {
	return AMOSTRA_PRONTA;
}

SENSOR_RETORNO LER_DADOS_PORT(void) {
	return AMOSTRA_OK;
}

SENSOR_RETORNO INTERPRETA_DADOS_PORT(void) {
	return DADOS_INVALIDOS;
}

SENSOR_RETORNO VERIFICA_TIPO_FALHA_PORT(void) {
	return FALHA_RECUPERAVEL;
}

SENSOR_RETORNO DESCONFIGURA_SENSOR_PORT(void) {
	return DESCONFIGURACAO_OK;
}
