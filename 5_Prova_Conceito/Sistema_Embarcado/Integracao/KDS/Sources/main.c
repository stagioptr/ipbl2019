/* ###################################################################
**     Filename    : main.c
**     Project     : integracao
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-11-16, 19:37, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "free_rtos.h"
#include "MainTask.h"
#include "Radio.h"
#include "tempSensor.h"
#include "inertialTask.h"
#include "spiRadioTemp.h"
#include "gpio.h"
#include "DbgCs1.h"
#include "i2cInertial.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
semaphore_t radioIRQ_semaphore = NULL;
semaphore_t inertiaIRQ_semaphore = NULL;
semaphore_t SPI0_Semaphore = NULL;

msg_queue_t temperature_msg_queue[4*sizeof(float)];
msg_queue_t inertial_msg_queue[4*6*sizeof(float)];

msg_queue_t freeFall_msg_queue[4*sizeof(uint32_t)];

msg_queue_handler_t temperature_msg_queue_handler = NULL;
msg_queue_handler_t inertial_msg_queue_handler = NULL;

msg_queue_handler_t freeFall_msg_queue_handler = NULL;


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	OSA_SemaCreate(&radioIRQ_semaphore, 0);
	OSA_SemaCreate(&inertiaIRQ_semaphore, 0);
	OSA_SemaCreate(&SPI0_Semaphore, 1);

	temperature_msg_queue_handler = OSA_MsgQCreate(temperature_msg_queue, 4, sizeof(float));
	inertial_msg_queue_handler = OSA_MsgQCreate(inertial_msg_queue, 4, 6*sizeof(float));

	freeFall_msg_queue_handler = OSA_MsgQCreate(freeFall_msg_queue, 4, sizeof(uint32_t));

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
