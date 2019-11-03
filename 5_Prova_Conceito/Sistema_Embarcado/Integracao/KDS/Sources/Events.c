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
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif


/* User includes (#include below this line is not maintained by Processor Expert) */
extern semaphore_t nRF24L01_Radio_IRQ;

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

#ifdef spiTemp_IDX
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
void SPI0_IRQHandler(void)
{
#if spiTemp_DMA_MODE
  SPI_DRV_DmaIRQHandler(spiTemp_IDX);
#else
  SPI_DRV_IRQHandler(spiTemp_IDX);
#endif
  /* Write your code here ... */
}
#else
  /* This IRQ handler is not used by spiTemp component. The purpose may be
   * that the component has been removed or disabled. It is recommended to
   * remove this handler because Processor Expert cannot modify it according to
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by spiTemp component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

/*
** ===================================================================
**     Callback    : free_rtos_vApplicationIdleHook
**     Description : This callback occurs if the RTOS is idle. This
**     might be a good place to go into low power mode.
**     Parameters  : None
**     Returns : Nothing
** ===================================================================
*/
void free_rtos_vApplicationIdleHook(void)
{
  /* Write your code here ... */
}

#ifdef spiRadio_IDX
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
void SPI1_IRQHandler(void)
{
#if spiRadio_DMA_MODE
  SPI_DRV_DmaIRQHandler(spiRadio_IDX);
#else
  SPI_DRV_IRQHandler(spiRadio_IDX);
#endif
  /* Write your code here ... */
}
#else
  /* This IRQ handler is not used by spiRadio component. The purpose may be
   * that the component has been removed or disabled. It is recommended to
   * remove this handler because Processor Expert cannot modify it according to
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by spiRadio component.\
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
void PORTA_IRQHandler(void)
{
  /* Clear interrupt flag.*/
  PORT_HAL_ClearPortIntFlag(PORTA_BASE_PTR);
  /* Write your code here ... */
  xSemaphoreGive(nRF24L01_Radio_IRQ);
}

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
