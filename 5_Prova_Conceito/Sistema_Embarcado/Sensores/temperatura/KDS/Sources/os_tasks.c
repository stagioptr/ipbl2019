/* ###################################################################
**     Filename    : os_tasks.c
**     Project     : MAX6675
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-31, 10:19, # CodeGen: 2
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         TaskTemperatura_task - void TaskTemperatura_task(os_task_param_t task_init_data);
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
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "MAX6675_API.h"

float temperature = 0.0;


/*
** ===================================================================
**     Callback    : TaskTemperatura_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void TaskTemperatura_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	uint16_t max6675Value = 0;

  if( MAX6675_Init() )
  	while(1) OSA_TimeDelay(10);

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

  	if( MAX6675_readValue( &max6675Value ) )
  		while(1) OSA_TimeDelay(10);

  	temperature = MAX6675_convertValueToCelsiusDegree( max6675Value );

  	debug_printf("%5.2f\n\r",temperature );

    OSA_TimeDelay(250);                 /* Example code (for task release) */


#ifdef PEX_USE_RTOS
  }
#endif
}

/* END os_tasks */

#ifdef __cplusplus
}  /* extern "C" */
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
