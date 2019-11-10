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
#include "ledrgb_hal.h"

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
	uint8_t reset_status_code;
	uint8_t codigo_erro;
	uint8_t a_x;
	uint8_t a_y;
	uint8_t a_z;
	uint8_t g_x;
	uint8_t g_y;
	uint8_t g_z;
	uint8_t temperature;
	uint8_t is_free_fall;
	uint8_t free_fall_threshold;
	uint8_t accelGetXYZ_status_code;
	uint8_t gyroGetXYZ_status_code;
	uint8_t set_accel_pw_on_delay_status_code;
	uint8_t free_fall_get_status_code;
	uint8_t int_ff_set_status_code;
	uint8_t int_zm_set_status_code;
	uint8_t int_me_set_status_code;
	uint8_t ff_th_set_status_code;
	uint8_t ff_dr_set_status_code;
	uint8_t dhpf_monde_set_status_code;
	uint8_t activites_status_code;
	int teste;
	int cont = 0;

  
  /* Initialization of Processor Expert components (when some RTOS is active). DON'T REMOVE THIS CODE!!! */
#ifdef MainTask_PEX_RTOS_COMPONENTS_INIT
  PEX_components_init(); 
#endif 
  /* End of Processor Expert components initialization.  */

  ledrgb_init();

  while (cont <= 3) {
	  //Start MPU6050
	  //reset_status_code = MPU6050_SetDeviceReset(1);
	  init_status_code = MPU6050_Init();
	  if (init_status_code == kStatus_I2C_Success)
		  break;
	  cont = cont + 1; //breakpoint here
  }


#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
/*
	  if(init_example()){
		  teste = 1;
	  }else {
		  teste = 0;
	  }
	  teste = teste + 1;

	  whoami = MPU6050_WhoAmI();
	  */

	  //breakpoint below this line
	  while( GPIO_DRV_ReadPinInput( J2_2 ) == 1 ){
		  //Get Accel
		  //codigo_erro = MPU6050_ReadReg8( MPU6050_ACCEL_XOUT_H, &a_x );
		  //codigo_erro = MPU6050_ReadReg8( MPU6050_ACCEL_YOUT_H, &a_y );
		  //codigo_erro = MPU6050_ReadReg8( MPU6050_ACCEL_ZOUT_H, &a_z );
		  accelGetXYZ_status_code = MPU6050_GetAccelXYZ(&a_x, &a_y, &a_z);

		  //Get Gyro
		  //codigo_erro = MPU6050_ReadReg8( MPU6050_GYRO_XOUT_H, &g_x );
		  //codigo_erro = MPU6050_ReadReg8( MPU6050_GYRO_YOUT_H, &g_y );
		  //codigo_erro = MPU6050_ReadReg8( MPU6050_GYRO_ZOUT_H, &g_z );
		  gyroGetXYZ_status_code = MPU6050_GetGyroXYZ(&g_x, &g_y, &g_z);

		  //Get Temperature
		  temperature = MPU6050_GetTemperature();

		  //Free fall detection

		  //Additional delay of acceleration 3ms
		  set_accel_pw_on_delay_status_code = MPU6050_SetAccelPowerOnDelay(MPU6050_DELAY_3MS);

		  //Enable hardware interrupt support for free fall action

		  //Int Free Fall
		  int_ff_set_status_code = MPU6050_SetIntFreeFallEnabled(1);

		  //Int Zero Motion
		  int_zm_set_status_code =  MPU6050_SetIntZeroMotionEnabled(0);

		  //Int Motion
		  int_me_set_status_code = MPU6050_SetIntMotionEnabled(0);

		  //Set high-pass filter (NOT OK)
		  dhpf_monde_set_status_code = MPU6050_SetDHPFMode(MPU6050_DHPF_5HZ);

		  //Set Free Fall threshold (NOT OK)
		  ff_th_set_status_code = MPU6050_SetFreeFallDetectionThreshold(50);

		  //Set duration (NOT OK)
		  ff_dr_set_status_code = MPU6050_SetFreeFallDetectionDuration(2);

		  //Get free fall (NOT OK)
		  free_fall_get_status_code = MPU6050_GetFreeFallDetectionThreshold(&free_fall_threshold);

		  while (1) {
			  activites_status_code = MPU6050_ReadActivites(&is_free_fall);
			  if (is_free_fall) {
				  ledrgb_clearGreenLed();
				  ledrgb_setRedLed();
				  OSA_TimeDelay(100);
			  } else {
				  ledrgb_clearRedLed();
				  //ledrgb_setGreenLed();
			  }
		  }

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
