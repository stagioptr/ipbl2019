/*
 ******************************************************************************
 * @file    shellStateMachine.c
 * @author  Vítor Eduardo Sabadine da Cruz
 * @version 0
 * @date    November-06-2019
 * @brief   Functions for debug in shell format.
 ******************************************************************************
 */

#include "shellStateMachine.h"

#include "stdint.h"
#include "stdio.h"
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

/*
 * Menu text definition
 */
char mainMenu[] = "\033\143\
*******************************************************************************\n\r\
******************** STAGIOP-TR - DEVICE SHELL TERMINAL ***********************\n\r\
*******************************************************************************\n\r\
For debug purposes, this terminal can be helpful to analise inconsistencies\n\r\
while the operational system is running.\n\r\n\r\
                                Main Menu\n\r\n\r\
\
1- OS Pause\n\r\
2- OS Show task states\n\r\
3- OS Resume\n\r\
4- Show real-time application log\n\r\n\r\
\
";

char systemRunningString[] = "\
The system is currently running.\n\r\n\r\
";

char systemSuspendedString[] = "\
The system is currently suspended.\n\r\n\r\
";

typedef enum {
	SYSTEM_SUSPENDED,
	SYSTEM_RUNNING,
} systemStateEnum_t;


/*
 * Definition of machine's states.
 */
typedef enum {
	PRINTING_MENU,
	WAITING_COMMAND,
	SUSPENDING_OS,
	RESUMMING_OS,
	SHOWING_TASK_STATES,
	PRINTING_REAL_TIME_LOG,
	EXITING_MACHINE
} shellStateEnum_t;

extern task_handler_t MainTask_task_handler;
extern task_handler_t Shell_task_handler;
extern task_handler_t Radio_task_handler;
extern task_handler_t tempSensor_task_handler;

#define		MAIN_TASK_ENTRY_POINT_NAME						"main_task"
#define		SHELL_TASK_ENTRY_POINT_NAME						"Shell_task"
#define		RADIO_TASK_ENTRY_POINT_NAME						"Radio_task"
#define		TEMPSENSOR_TASK_ENTRY_POINT_NAME			"tempSensor_task"
#define		IDLE_TASK_ENTRY_POINT_NAME						"prvIdleTask"
#define		TMRSVC_TASK_ENTRY_POINT_NAME					"prvTimerTask"

#define		TASK_STATUS_RUNNING										"running"
#define		TASK_STATUS_READY											"ready"
#define		TASK_STATUS_BLOCKED										"blocked"
#define		TASK_STATUS_SUSPENDED									"suspended"
#define		TASK_STATUS_DELETED										"deleted"

#if defined DEBUG
	extern QueueHandle_t radio_debug_msg_queue_handler;
	extern QueueHandle_t temperature_debug_msg_queue_handler;
#endif

/*
 * Copy the string without the termination character '\0'.
 */
void strcpy_alt ( char* to, const char* from ) {
	for( uint32_t loop=0; from[loop]!='\0'; loop++ )
		to[loop] = from[loop];
}

char* itoa(int i, char b[]){
	char const digit[] = "0123456789";
	char* p = b;
	if(i<0){
			*p++ = '-';
			i *= -1;
	}
	int shifter = i;
	do{ //Move to where representation ends
			++p;
			shifter = shifter/10;
	}while(shifter);
//	*p = '\0';
	do{ //Move back, inserting digits as u go
			*--p = digit[i%10];
			i = i/10;
	}while(i);
	return b;
}

/*
 * Machine state control variables.
 */
static shellStateEnum_t state = PRINTING_MENU;
static systemStateEnum_t systemState = SYSTEM_RUNNING;

void shell_stateMachine(void) {
	while(1){
		switch( state ) {
		case PRINTING_MENU:
			debug_printf("%s", mainMenu);
			if( systemState == SYSTEM_RUNNING )
				debug_printf("%s", systemRunningString);
			else if( systemState == SYSTEM_SUSPENDED )
				debug_printf("%s", systemSuspendedString);

			state = WAITING_COMMAND;
			break;

		case WAITING_COMMAND:
		{
			char keyPressed = 0;

			keyPressed = debug_getchar();

			if( keyPressed == '1' && systemState == SYSTEM_RUNNING )
				state = SUSPENDING_OS;
			else if( keyPressed == '2' && systemState == SYSTEM_SUSPENDED )
				state = SHOWING_TASK_STATES;
			else if( keyPressed == '3' && systemState == SYSTEM_SUSPENDED )
				state = RESUMMING_OS;
			else if( keyPressed == '4' && systemState == SYSTEM_RUNNING ) {
				xQueueReset(radio_debug_msg_queue_handler);
				xQueueReset(temperature_debug_msg_queue_handler);
				state = PRINTING_REAL_TIME_LOG;
			}
			else
				state = PRINTING_MENU;
		}
			break;

		case SHOWING_TASK_STATES:
		{
			char keyPressed = 0;

			TaskStatus_t *pxTaskStatusArray;
			volatile UBaseType_t uxArraySize, x;
			unsigned long ulTotalRunTime;

		 /* Take a snapshot of the number of tasks in case it changes while this
		 function is executing. */
		 uxArraySize = uxTaskGetNumberOfTasks();

		 /* Allocate a TaskStatus_t structure for each task.  An array could be
		 allocated statically at compile time. */
		 pxTaskStatusArray = pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );

		 if( pxTaskStatusArray != NULL )
		 {
				/* Generate raw status information about each task. */
				uxArraySize = uxTaskGetSystemState( pxTaskStatusArray,
																	 uxArraySize,
																	 &ulTotalRunTime );

				/* For percentage calculations. */
				ulTotalRunTime /= 100UL;

				/* Avoid divide by zero errors. */
				if( ulTotalRunTime > 0 )
				{
					debug_printf( "TASK NAME    ENTRY POINT           ID    PRIORITY     STATUS     TCOMP\n\r\n\r");
					 /* For each populated position in the pxTaskStatusArray array,
					 format the raw data as human readable ASCII data. */
					 for( x = 0; x < uxArraySize; x++ )
					 {
						 char* entryPoint = 0;
						 char* taskStatus = 0;
						 char text[] = "$            $                     $     $            $          $       \n\r";
						 uint8_t cursorPosition = 0;


						 if( pxTaskStatusArray[ x ].xHandle == MainTask_task_handler ) {
							 entryPoint = MAIN_TASK_ENTRY_POINT_NAME;
						 }
						 else if( pxTaskStatusArray[ x ].xHandle == xTaskGetIdleTaskHandle() ) {
							 entryPoint = IDLE_TASK_ENTRY_POINT_NAME;
						 }
						 else if( pxTaskStatusArray[ x ].xHandle == xTimerGetTimerDaemonTaskHandle() ) {
							 entryPoint = TMRSVC_TASK_ENTRY_POINT_NAME;
						 }
						 else if( pxTaskStatusArray[ x ].xHandle == tempSensor_task_handler ) {
							 entryPoint = TEMPSENSOR_TASK_ENTRY_POINT_NAME;
						 }
						 else if( pxTaskStatusArray[ x ].xHandle == Radio_task_handler ) {
							 entryPoint = RADIO_TASK_ENTRY_POINT_NAME;
						 }
						 else if( pxTaskStatusArray[ x ].xHandle == Shell_task_handler ) {
							 entryPoint = SHELL_TASK_ENTRY_POINT_NAME;
						 }

						 switch(pxTaskStatusArray[ x ].eCurrentState) {
						 case eRunning:
							 taskStatus = TASK_STATUS_RUNNING;
							 break;
						 case eReady:
							 taskStatus = TASK_STATUS_READY;
							 break;
						 case eBlocked:
							 taskStatus = TASK_STATUS_BLOCKED;
							 break;
						 case eSuspended:
							 taskStatus = TASK_STATUS_SUSPENDED;
							 break;
						 case eDeleted:
							 taskStatus = TASK_STATUS_DELETED;
							 break;
						 }

						 for(cursorPosition=0; text[cursorPosition] != '$' && cursorPosition<sizeof(text); cursorPosition++);
						 strcpy_alt(&text[cursorPosition],pxTaskStatusArray[ x ].pcTaskName);

						 for(; text[cursorPosition] != '$' && cursorPosition<sizeof(text); cursorPosition++);
						 strcpy_alt(&text[cursorPosition],entryPoint);

						 for(; text[cursorPosition] != '$' && cursorPosition<sizeof(text); cursorPosition++);
						 itoa( pxTaskStatusArray[ x ].xTaskNumber, &text[cursorPosition] );

						 for(; text[cursorPosition] != '$' && cursorPosition<sizeof(text); cursorPosition++);
						 itoa( pxTaskStatusArray[ x ].uxCurrentPriority, &text[cursorPosition] );

						 for(; text[cursorPosition] != '$' && cursorPosition<sizeof(text); cursorPosition++);
						 strcpy_alt(&text[cursorPosition],taskStatus);

						 for(; text[cursorPosition] != '$' && cursorPosition<sizeof(text); cursorPosition++);
						 itoa( pxTaskStatusArray[ x ].ulRunTimeCounter, &text[cursorPosition] );

						 debug_printf( "%s", text );
/*						 debug_printf( "%s  %s  %d  %d  %s  %d\n\r",
																 pxTaskStatusArray[ x ].pcTaskName,
																 entryPoint,
																 pxTaskStatusArray[ x ].xTaskNumber,
																 pxTaskStatusArray[ x ].uxCurrentPriority,
																 taskStatus,
																 pxTaskStatusArray[ x ].ulRunTimeCounter );*/
					 }
				}

				/* The array is no longer needed, free the memory it consumes. */
				vPortFree( pxTaskStatusArray );
				debug_printf("\n\rPress any key to continue...\n\r");
				keyPressed = debug_getchar();
		 	}
		}

			state = PRINTING_MENU;

			break;

		case SUSPENDING_OS:
			vTaskSuspendAll();

			systemState = SYSTEM_SUSPENDED;

			state = PRINTING_MENU;
			break;

		case RESUMMING_OS:
			xTaskResumeAll();

			systemState = SYSTEM_RUNNING;

			state = PRINTING_MENU;
			break;

		case PRINTING_REAL_TIME_LOG:
		{
			radioDebugCodeEnum_t radioMsg = SHELL_DEBUG_RADIO_NO_EVENT;
			float temperatureValue = -1.0;

			if( xQueueReceive( radio_debug_msg_queue_handler, &radioMsg, portMAX_DELAY ) == pdPASS ) {
				if( radioMsg == SHELL_DEBUG_RADIO_EVENT_MISSING_DATA ){
						debug_printf("Radio: Missing data to send!\n\r");
						xQueueReset(radio_debug_msg_queue_handler);
						xQueueReset(temperature_debug_msg_queue_handler);
				}
				else if( xQueueReceive( temperature_debug_msg_queue_handler, &temperatureValue, 1000 ) == pdPASS ) {
					debug_printf("Temperature: %5.2f Celsius Degree; ", temperatureValue );

					if( radioMsg == SHELL_DEBUG_RADIO_EVENT_SEND_NO_ACK ){
						debug_printf("Radio: transmission failed!\n\r");
					}
					else if( radioMsg == SHELL_DEBUG_RADIO_EVENT_SEND_OK ) {
						debug_printf("Radio: transmission succeed!\n\r");
					}
				}
				else {
					debug_printf("Temperature: Missing data!\n\r");
					xQueueReset(radio_debug_msg_queue_handler);
					xQueueReset(temperature_debug_msg_queue_handler);
				}
			}

		}
			break;
		case EXITING_MACHINE:
		default:
			return;
		}
	}
}
