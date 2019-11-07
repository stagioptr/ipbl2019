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
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

/*
 * Menu text definition
 */
char mainMenu[] = "\
*******************************************************************************\n\r\
******************** STAGIOP-TR - DEVICE SHELL TERMINAL ***********************\n\r\
*******************************************************************************\n\r\
For debug purposes, this terminal can be helpful to analise inconsistencies\n\r\
while the operational system is running.\n\r\n\r\
                                Main Menu\n\r\n\r\
\
1- OS Pause\n\r\
2- OS Show task states\n\r\
3- OS Resume\n\r\n\r\
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
	WAIT_COMMAND,
	SUSPENDING_OS,
	RESUMMING_OS,
	SHOW_TASK_STATES,
	PRINTING_REAL_TIME_LOG,
	EXIT_MACHINE
} shellStateEnum_t;

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

			state = WAIT_COMMAND;
			break;

		case WAIT_COMMAND:
		{
			char keyPressed = 0;

			keyPressed = debug_getchar();

			if( keyPressed == '1' && systemState == SYSTEM_RUNNING )
				state = SUSPENDING_OS;
			else if( keyPressed == '2' && systemState == SYSTEM_SUSPENDED )
				state = SHOW_TASK_STATES;
			else if( keyPressed == '3' && systemState == SYSTEM_SUSPENDED )
				state = RESUMMING_OS;
		}
			break;

		case SHOW_TASK_STATES:
		{
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
					debug_printf( "TASK NAME    ENTRY POINT    ID    PRIORITY     STATUS     TCOMP\n\r\n\r");
					 /* For each populated position in the pxTaskStatusArray array,
					 format the raw data as human readable ASCII data. */
					 for( x = 0; x < uxArraySize; x++ )
					 {
						 char* entryPoint = 0;
						 char* taskStatus = 0;

						 switch(pxTaskStatusArray[ x ].xTaskNumber) {
						 case 1:
							 entryPoint = MAIN_TASK_ENTRY_POINT_NAME;
							 break;
						 case 2:
							 entryPoint = IDLE_TASK_ENTRY_POINT_NAME;
							 break;
						 case 3:
							 entryPoint = TMRSVC_TASK_ENTRY_POINT_NAME;
							 break;
						 case 4:
							 entryPoint = TEMPSENSOR_TASK_ENTRY_POINT_NAME;
							 break;
						 case 5:
							 entryPoint = RADIO_TASK_ENTRY_POINT_NAME;
							 break;
						 case 6:
							 entryPoint = SHELL_TASK_ENTRY_POINT_NAME;
							 break;
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

						 debug_printf( "%s  %s  %d  %d  %s  %d\n\r",
																 pxTaskStatusArray[ x ].pcTaskName,
																 entryPoint,
																 pxTaskStatusArray[ x ].xTaskNumber,
																 pxTaskStatusArray[ x ].uxCurrentPriority,
																 taskStatus,
																 pxTaskStatusArray[ x ].ulRunTimeCounter );
					 }
				}

				/* The array is no longer needed, free the memory it consumes. */
				vPortFree( pxTaskStatusArray );
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

		case EXIT_MACHINE:
		default:
			return;
		}
	}
}
