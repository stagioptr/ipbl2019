/* ###################################################################
 **     Filename    : os_tasks.c
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
#include "nRF24L01_API.h"
#include "Protocol_API.h"

/*
 ** ===================================================================
 **     Callback    : TaskRadio2_task
 **     Description : Task function entry.
 **     Parameters  :
 **       task_init_data - OS task parameter
 **     Returns : Nothing
 ** ===================================================================
 */
uint8_t teste[32];
void TaskRadio2_task(os_task_param_t task_init_data) {
	/* Write your local variable definition here */
	nRF24L01_Init();
	OSA_TimeDelay(2000); /* Example code (for task release) */
	nRF24L01_TX_Mode();
	/*
	 OSA_TimeDelay(2000);  Example code (for task release)
	 L01_Read_RX_Pload(teste);
	 */

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
 **     Callback    : TaskRadio1_task
 **     Description : Task function entry.
 **     Parameters  :
 **       task_init_data - OS task parameter
 **     Returns : Nothing
 ** ===================================================================
 */
const uint8_t valores[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

void TaskRadio1_task(os_task_param_t task_init_data) {
	/* Write your local variable definition here */
	uint8_t loop;

	nRF24L01_Init();
	nRF24L01_RX_Mode();
	OSA_TimeDelay(3000); /* Example code (for task release) */
	L01_Read_RX_Pload(teste);

	for (loop = 0; loop < sizeof(valores); loop++)
		if (valores[loop] != teste[loop])
			break;

	if (loop >= sizeof(valores))
		GPIO_DRV_WritePinOutput(LEDRGB_GREEN, 0);
	else
		GPIO_DRV_WritePinOutput(LEDRGB_RED, 0);
#ifdef PEX_USE_RTOS
	while (1) {
#endif
	/* Write your code here ... */

	OSA_TimeDelay(10); /* Example code (for task release) */

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
