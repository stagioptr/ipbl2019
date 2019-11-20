################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
N:/SCADE/publish/versao0/Integration_Integration.c \
N:/SCADE/publish/versao0/accellerometerSensor_AccellerometerSensor.c \
N:/SCADE/publish/versao0/humiditySensor_HumiditySensor.c \
N:/SCADE/publish/versao0/kcg_consts.c \
N:/SCADE/publish/versao0/kcg_types.c \
N:/SCADE/publish/versao0/rangeChecker_TemperatureSensor.c \
N:/SCADE/publish/versao0/tempratureSensor_TemperatureSensor.c 

OBJS += \
./SCADE/Integration_Integration.o \
./SCADE/accellerometerSensor_AccellerometerSensor.o \
./SCADE/humiditySensor_HumiditySensor.o \
./SCADE/kcg_consts.o \
./SCADE/kcg_types.o \
./SCADE/rangeChecker_TemperatureSensor.o \
./SCADE/tempratureSensor_TemperatureSensor.o 

C_DEPS += \
./SCADE/Integration_Integration.d \
./SCADE/accellerometerSensor_AccellerometerSensor.d \
./SCADE/humiditySensor_HumiditySensor.d \
./SCADE/kcg_consts.d \
./SCADE/kcg_types.d \
./SCADE/rangeChecker_TemperatureSensor.d \
./SCADE/tempratureSensor_TemperatureSensor.d 


# Each subdirectory must supply rules for building sources it contributes
SCADE/Integration_Integration.o: N:/SCADE/publish/versao0/Integration_Integration.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -I"N:\Sensores\temperatura\publish\versao1" -I"N:\SCADE\publish\versao0" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SCADE/accellerometerSensor_AccellerometerSensor.o: N:/SCADE/publish/versao0/accellerometerSensor_AccellerometerSensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -I"N:\Sensores\temperatura\publish\versao1" -I"N:\SCADE\publish\versao0" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SCADE/humiditySensor_HumiditySensor.o: N:/SCADE/publish/versao0/humiditySensor_HumiditySensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -I"N:\Sensores\temperatura\publish\versao1" -I"N:\SCADE\publish\versao0" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SCADE/kcg_consts.o: N:/SCADE/publish/versao0/kcg_consts.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -I"N:\Sensores\temperatura\publish\versao1" -I"N:\SCADE\publish\versao0" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SCADE/kcg_types.o: N:/SCADE/publish/versao0/kcg_types.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -I"N:\Sensores\temperatura\publish\versao1" -I"N:\SCADE\publish\versao0" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SCADE/rangeChecker_TemperatureSensor.o: N:/SCADE/publish/versao0/rangeChecker_TemperatureSensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -I"N:\Sensores\temperatura\publish\versao1" -I"N:\SCADE\publish\versao0" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SCADE/tempratureSensor_TemperatureSensor.o: N:/SCADE/publish/versao0/tempratureSensor_TemperatureSensor.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -I"N:\Sensores\temperatura\publish\versao1" -I"N:\SCADE\publish\versao0" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


