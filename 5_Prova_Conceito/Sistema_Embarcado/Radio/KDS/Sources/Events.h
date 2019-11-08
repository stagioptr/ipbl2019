/* ###################################################################
**     Filename    : Events.h
**     Project     : radio
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-13, 15:02, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

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


#ifdef Radio1_IDX
/*
** ===================================================================
**     Interrupt handler : SPI0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SPI0_IRQHandler(void);
#else
  /* This IRQ handler is not used by Radio1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by Radio1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

#ifdef Radio2_IDX
/*
** ===================================================================
**     Interrupt handler : SPI1_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SPI1_IRQHandler(void);
#else
  /* This IRQ handler is not used by Radio2 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by Radio2 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

/*
** ===================================================================
**     Interrupt handler : PORTA_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTA_IRQHandler(void);

/*
** ===================================================================
**     Interrupt handler : PORTD_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTD_IRQHandler(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
