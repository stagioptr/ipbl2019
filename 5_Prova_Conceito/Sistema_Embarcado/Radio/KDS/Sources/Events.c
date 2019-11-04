/* ###################################################################
**     Filename    : Events.c
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
extern semaphore_t nRF24L01_Radio1_IRQ;
extern semaphore_t nRF24L01_Radio2_IRQ;

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
void SPI0_IRQHandler(void)
{
#if Radio1_DMA_MODE
  SPI_DRV_DmaIRQHandler(Radio1_IDX);
#else
  SPI_DRV_IRQHandler(Radio1_IDX);
#endif
  /* Write your code here ... */
}
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
void SPI1_IRQHandler(void)
{
#if Radio2_DMA_MODE
  SPI_DRV_DmaIRQHandler(Radio2_IDX);
#else
  SPI_DRV_IRQHandler(Radio2_IDX);
#endif
  /* Write your code here ... */
}
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
void PORTA_IRQHandler(void)
{
  /* Clear interrupt flag.*/
  PORT_HAL_ClearPortIntFlag(PORTA_BASE_PTR);
  /* Write your code here ... */
  /*Radio 2 */
  xSemaphoreGive(nRF24L01_Radio2_IRQ);
}

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
void PORTD_IRQHandler(void)
{
  /* Clear interrupt flag.*/
  PORT_HAL_ClearPortIntFlag(PORTD_BASE_PTR);
  /* Write your code here ... */
  /*Radio 1 */
  xSemaphoreGive(nRF24L01_Radio1_IRQ);
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
