/* ###################################################################
**     Filename    : os_tasks.h
**     Project     : radio
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-14, 15:17, # CodeGen: 9
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         TaskRadio2_task - void TaskRadio2_task(os_task_param_t task_init_data);
**         TaskRadio1_task - void TaskRadio1_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file os_tasks.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup os_tasks_module os_tasks module documentation
**  @{
*/         

#ifndef __os_tasks_H
#define __os_tasks_H
/* MODULE os_tasks */

#include "fsl_device_registers.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "free_rtos.h"
#include "MainTask.h"
#include "Radio1.h"
#include "Radio2.h"
#include "gpio1.h"
#include "TaskRadio1.h"
#include "TaskRadio2.h"
#include "DbgCs1.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Callback    : TaskRadio2_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void TaskRadio2_task(os_task_param_t task_init_data);

/*
** ===================================================================
**     Callback    : TaskRadio1_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void TaskRadio1_task(os_task_param_t task_init_data);


/* END os_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __os_tasks_H*/
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
