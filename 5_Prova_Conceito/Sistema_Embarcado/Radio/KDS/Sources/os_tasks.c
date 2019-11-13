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
#include "string.h"
#include "nRF24L01_API.h"

extern semaphore_t nRF24L01_Radio1_IRQ;
extern semaphore_t nRF24L01_Radio2_IRQ;

/*
 ** ===================================================================
 **     Callback    : TaskRadio2_task
 **     Description : Task function entry.
 **     Parameters  :
 **       task_init_data - OS task parameter
 **     Returns : Nothing
 ** ===================================================================
 */
void TaskRadio2_task(os_task_param_t task_init_data) {
	/* Write your local variable definition here */
	uint8_t transmitPayload[16] = "Trasmitindo2";
	uint8_t receivePayload[16] = "\0";

	NRF24L01_transferSetupStruct_t transmitSetup = {
			.payload = transmitPayload,
			.payloadWidth = 16,
			.address = { 0x34, 0x43, 0x10, 0x10, 0x01 },
			.addressLength = 5
	};

	NRF24L01_transferSetupStruct_t receiveSetup = {
			.payload = receivePayload,
			.payloadWidth = 16,
			.address = { 0x34, 0x43, 0x10, 0x10, 0x02 },
			.addressLength = 5
	};

	uint8_t radio2_status = 0;
//	uint8_t registers[0x17];

	nRF24L01_Init();
	OSA_TimeDelay(100); /* Example code (for task release) */
	nRF24L01_transmitPayload( &transmitSetup );
//	radio2_status = nRF24L01_readStatus();
	/*
	 OSA_TimeDelay(2000);  Example code (for task release)
	 L01_Read_RX_Pload(teste);
	 */
//	nRF24L01_getAllRegisters( registers );
#ifdef PEX_USE_RTOS
	while (1) {
#endif
	/* Write your code here ... */
		if( xSemaphoreTake( nRF24L01_Radio2_IRQ, pdMS_TO_TICKS(1000) ) == pdFALSE ){
//		while(1);
			GPIO_DRV_WritePinOutput(LEDRGB_RED, 0);
		}

		radio2_status = nRF24L01_readStatus();

		if( radio2_status & NRF24L01_MAX_RT ) {
			L01_Clear_IRQ( NRF24L01_MAX_RT );
		}

		if( radio2_status & NRF24L01_TX_DS ) {
			L01_Clear_IRQ( NRF24L01_TX_DS );
			memset(receivePayload, 0, 16);
			nRF24L01_receivePayload( &receiveSetup );
		}

		if( radio2_status & NRF24L01_RX_DR ) {
			L01_Read_RX_Pload( receivePayload );
			L01_Clear_IRQ( NRF24L01_RX_DR );
			if( memcmp( receivePayload, "Trasmitindo1", 16) != 0 )
				GPIO_DRV_WritePinOutput(LEDRGB_RED, 0);
			OSA_TimeDelay(100); /* Example code (for task release) */
			nRF24L01_transmitPayload( &transmitSetup );
		}

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
void TaskRadio1_task(os_task_param_t task_init_data) {
	/* Write your local variable definition here */
	uint8_t transmitPayload[16] = "Trasmitindo1";
	uint8_t receivePayload[16] = "\0";

	NRF24L01_transferSetupStruct_t transmitSetup = {
			.payload = transmitPayload,
			.payloadWidth = 16,
			.address = { 0x34, 0x43, 0x10, 0x10, 0x02 },
			.addressLength = 5
	};

	NRF24L01_transferSetupStruct_t receiveSetup = {
			.payload = receivePayload,
			.payloadWidth = sizeof(float),
			.address = { 0x10, 0x20, 0x30, 0x40, 0x01 },
			.addressLength = 5
	};

	uint8_t radio1_status = 0;
//	uint8_t registers[0x17];

	nRF24L01_Init();
	OSA_TimeDelay(10); /* Example code (for task release) */
	nRF24L01_receivePayload( &receiveSetup );
//	radio1_status = nRF24L01_readStatus();

//	nRF24L01_getAllRegisters( registers );
#ifdef PEX_USE_RTOS
	while (1) {
#endif
	/* Write your code here ... */

		if( xSemaphoreTake( nRF24L01_Radio1_IRQ, pdMS_TO_TICKS(1000) ) == pdFALSE ){
//			while(1);
			debug_printf("Radio reception timeout...\n\r");
			GPIO_DRV_WritePinOutput(LEDRGB_RED, 0);
		}

		radio1_status = nRF24L01_readStatus();

		if( radio1_status & NRF24L01_MAX_RT ) {
			L01_Clear_IRQ( NRF24L01_MAX_RT );
		}

		if( radio1_status & NRF24L01_TX_DS ) {
			L01_Clear_IRQ( NRF24L01_TX_DS );
		}

		if( radio1_status & NRF24L01_RX_DR ) {
			float temperature = 0.0;

			L01_Read_RX_Pload( receivePayload );
			L01_Clear_IRQ( NRF24L01_RX_DR );

			temperature = *((float*)receivePayload);
			debug_printf("Received value: %5.2f Celsius Degree\n\r", temperature );
		}

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
