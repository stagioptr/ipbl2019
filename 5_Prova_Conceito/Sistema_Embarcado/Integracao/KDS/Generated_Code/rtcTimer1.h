/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : rtcTimer1.h
**     Project     : integracao
**     Processor   : MKL25Z128VLK4
**     Component   : fsl_rtc
**     Version     : Component 1.3.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-10-03, 17:34, # CodeGen: 1
**     Contents    :
**         RTC_DRV_Init                - rtc_status_t RTC_DRV_Init(uint32_t instance);
**         RTC_DRV_Deinit              - void RTC_DRV_Deinit(uint32_t instance);
**         RTC_DRV_SetDatetime         - bool RTC_DRV_SetDatetime(uint32_t instance,rtc_datetime_t * datetime);
**         RTC_DRV_GetDatetime         - void RTC_DRV_GetDatetime(uint32_t instance,rtc_datetime_t * datetime);
**         RTC_DRV_SetAlarm            - bool RTC_DRV_SetAlarm(uint32_t instance,rtc_datetime_t * alarmTime,bool...
**         RTC_DRV_GetAlarm            - void RTC_DRV_GetAlarm(uint32_t instance,rtc_datetime_t * date);
**         RTC_DRV_InitRepeatAlarm     - void RTC_DRV_InitRepeatAlarm(uint32_t instance,rtc_repeat_alarm_state_t *...
**         RTC_DRV_SetAlarmRepeat      - bool RTC_DRV_SetAlarmRepeat(uint32_t instance,rtc_datetime_t *...
**         RTC_DRV_DeinitRepeatAlarm   - void RTC_DRV_DeinitRepeatAlarm(uint32_t instance);
**         RTC_IRQHandler              - void RTC_IRQHandler(void);
**         RTC_Seconds_IRQHandler      - void RTC_Seconds_IRQHandler(void);
**         RTC_DRV_IsCounterEnabled    - bool RTC_DRV_IsCounterEnabled(uint32_t instance);
**         RTC_DRV_SetSecsIntCmd       - void RTC_DRV_SetSecsIntCmd(uint32_t instance,bool secondsEnable);
**         RTC_DRV_SetAlarmIntCmd      - void RTC_DRV_SetAlarmIntCmd(uint32_t instance,bool alarmEnable);
**         RTC_DRV_GetAlarmIntCmd      - bool RTC_DRV_GetAlarmIntCmd(uint32_t instance);
**         RTC_DRV_IsAlarmPending      - bool RTC_DRV_IsAlarmPending(uint32_t instance);
**         RTC_DRV_SetTimeCompensation - void RTC_DRV_SetTimeCompensation(uint32_t instance,uint32_t...
**         RTC_DRV_GetTimeCompensation - void RTC_DRV_GetTimeCompensation(uint32_t instance,uint32_t *...
**         RTC_DRV_AlarmIntAction      - void RTC_DRV_AlarmIntAction(uint32_t instance);
**         RTC_DRV_SecsIntAction       - void RTC_DRV_SecsIntAction(uint32_t instance);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file rtcTimer1.h
** @version 01.00
*/         
/*!
**  @addtogroup rtcTimer1_module rtcTimer1 module documentation
**  @{
*/         
#ifndef __rtcTimer1_H
#define __rtcTimer1_H
/* MODULE rtcTimer1. */

/* Include inherited beans */
#include "clockMan1.h"
#include "Cpu.h"

/*! @brief Device instance number */
#define rtcTimer1_IDX RTC_IDX
/*! @brief Device instance number for backward compatibility */
#define FSL_RTCTIMER1 rtcTimer1_IDX


#endif
/* ifndef __rtcTimer1_H */
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