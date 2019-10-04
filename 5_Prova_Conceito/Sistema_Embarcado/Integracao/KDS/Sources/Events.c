/* ###################################################################
**     Filename    : Events.c
**     Project     : integracao
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-03, 17:31, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

#ifdef rtcTimer1_IDX
/*
** ===================================================================
**     Interrupt handler : RTC_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void RTC_IRQHandler(void)
{
  RTC_DRV_AlarmIntAction(rtcTimer1_IDX);
  /* Write your code here ... */
}
#else
  /* This IRQ handler is not used by rtcTimer1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by rtcTimer1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

/*
** ===================================================================
**     Interrupt handler : RTC_Seconds_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void RTC_Seconds_IRQHandler(void)
{
  /* Write your code here ... */
}

#ifdef tpmTmr2_IDX
/*
** ===================================================================
**     Interrupt handler : TPM2_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM2_IRQHandler(void)
{
  TPM_DRV_IRQHandler(tpmTmr2_IDX);
  /* Write your code here ... */
}
#else
  /* This IRQ handler is not used by tpmTmr2 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr2 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

#ifdef tpmTmr1_IDX
/*
** ===================================================================
**     Interrupt handler : TPM0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM0_IRQHandler(void)
{
  TPM_DRV_IRQHandler(tpmTmr1_IDX);
  /* Write your code here ... */
}
#else
  /* This IRQ handler is not used by tpmTmr1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

/* END Events */

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
