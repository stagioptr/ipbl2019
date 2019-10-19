/* ###################################################################
**     Filename    : rtos_main_task.c
**     Project     : acelerometro
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-15, 13:39, # CodeGen: 7
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         main_task - void main_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file rtos_main_task.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup rtos_main_task_module rtos_main_task module documentation
**  @{
*/         
/* MODULE rtos_main_task */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "mpu6050.h"

/* Initialization of Processor Expert components function prototype */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
extern void PEX_components_init(void);
#endif 

/*
** ===================================================================
**     Callback    : main_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void main_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */

	uint8_t whoami;
	uint8_t init_status_code;
	uint8_t codigo_erro;
	uint8_t a_x;
	uint8_t a_y;
	uint8_t a_z;
	uint8_t g_x;
	uint8_t g_y;
	uint8_t g_z;
	uint8_t temperature;
	int teste;


/*

	uint8_t codigoErro;
	uint8_t valor;
	uint8_t habilita = 1;
	uint8_t x = 0;
	uint8_t y = 0;
	uint8_t z = 0;
	uint8_t value;
	uint8_t deinit_status_code;
	uint8_t read;

*/

  
  /* Initialization of Processor Expert components (when some RTOS is active). DON'T REMOVE THIS CODE!!! */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
  PEX_components_init(); 
#endif 
  /* End of Processor Expert components initialization.  */

  init_status_code = MPU6050_Init();

  //codigoErro = MPU6050_WriteReg8( MPU6050_CTRL_REG_2, 0x40 );
  //OSA_TimeDelay(10);                 /* Example code (for task release) */

  //codigoErro = MPU6050_WriteReg8( MPU6050_CTRL_REG_4, 1 );
  //codigoErro = MPU6050_WriteReg8( MPU6050_CTRL_REG_5, 1 );

  //codigoErro = MPU6050_ReadReg8( MPU6050_CTRL_REG_4, &valor );
  //codigoErro = MPU6050_ReadReg8( MPU6050_CTRL_REG_5, &valor );

  //if( habilita == 1 )
	//codigoErro = MPU6050_Init();

  //codigoErro = MPU6050_ReadReg8( MPU6050_SYS_MODE_REG, &valor );

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  if(init_example()){
		  teste = 1;
	  }else {
		  teste = 0;
	  }
	  teste = teste + 1;

	  whoami = MPU6050_WhoAmI();

	  //read = read_test();
	  //deinit_status_code = MPU6050_Deinit();

	  while( GPIO_DRV_ReadPinInput( J2_2 ) == 1 ){
		  //Get Accel
		  codigo_erro = MPU6050_ReadReg8( MPU6050_ACCEL_XOUT_H, &a_x );
		  codigo_erro = MPU6050_ReadReg8( MPU6050_ACCEL_YOUT_H, &a_y );
		  codigo_erro = MPU6050_ReadReg8( MPU6050_ACCEL_ZOUT_H, &a_z );

		  //Get Gyro
		  codigo_erro = MPU6050_ReadReg8( MPU6050_GYRO_XOUT_H, &g_x );
		  codigo_erro = MPU6050_ReadReg8( MPU6050_GYRO_YOUT_H, &g_y );
		  codigo_erro = MPU6050_ReadReg8( MPU6050_GYRO_ZOUT_H, &g_z );

		  //Get Temperature
		  codigo_erro = MPU6050_ReadReg8( MPU6050_TEMP_OUT_H, &temperature);
		  OSA_TimeDelay(10);                 /* Example code (for task release) */

	    }




    
#ifdef PEX_USE_RTOS   
  }
#endif    
}

/* END rtos_main_task */

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
