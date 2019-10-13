/* ###################################################################
 **     Filename    : os_tasks.c
 **     Project     : integracao
 **     Processor   : MKL25Z128VLK4
 **     Component   : Events
 **     Version     : Driver 01.00
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2019-10-12, 14:38, # CodeGen: 11
 **     Abstract    :
 **         This is user's event module.
 **         Put your event handler code here.
 **     Settings    :
 **     Contents    :
 **         Sensor_task - void Sensor_task(os_task_param_t task_init_data);
 **
 ** ###################################################################*/
/*!
 ** @file os_tasks.c
 ** @version 01.00
 ** @brief
 **         This is user's event module.
 **         Put your event handler code here.
 */
/*!
 **  @addtogroup os_tasks_module os_tasks module documentation
 **  @{
 */
/* MODULE os_tasks */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "maquinaEstadoSensor.h"

/*
 ** ===================================================================
 **     Callback    : Sensor_task
 **     Description : Task function entry.
 **     Parameters  :
 **       task_init_data - OS task parameter
 **     Returns : Nothing
 ** ===================================================================
 */
void Sensor_task(os_task_param_t task_init_data) {
	/* Write your local variable definition here */
	sensor_stateMachine();

#ifdef PEX_USE_RTOS
	while (1) {
#endif
	/* Write your code here ... */

	OSA_TimeDelay(10); /* Example code (for task release) */

#ifdef PEX_USE_RTOS
}
#endif
}

/*
** ===================================================================
**     Callback    : Terminal_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Terminal_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
    
    
    OSA_TimeDelay(10);                 /* Example code (for task release) */
   
    
    
    
#ifdef PEX_USE_RTOS   
  }
#endif    
}

/* END os_tasks */

#ifdef __cplusplus
} /* extern "C" */
#endif

/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
