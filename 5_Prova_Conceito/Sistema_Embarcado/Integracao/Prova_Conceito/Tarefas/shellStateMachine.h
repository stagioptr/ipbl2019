/*
 ******************************************************************************
 * @file    shellStateMachine.h
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    November-06-2019
 * @brief   Functions for debug in shell format.
 ******************************************************************************
 */

typedef enum {
  SHELL_DEBUG_RADIO_EVENT_SEND_OK,
  SHELL_DEBUG_RADIO_EVENT_SEND_NO_ACK,
  SHELL_DEBUG_RADIO_EVENT_MISSING_DATA,
}radioDebugCodeEnum_t;

void shell_stateMachine(void);
