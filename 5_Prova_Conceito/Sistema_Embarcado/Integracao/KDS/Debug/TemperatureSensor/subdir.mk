################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
N:/Sensores/temperatura/publish/versao1/MAX6675_API.c 

OBJS += \
./TemperatureSensor/MAX6675_API.o 

C_DEPS += \
./TemperatureSensor/MAX6675_API.d 


# Each subdirectory must supply rules for building sources it contributes
TemperatureSensor/MAX6675_API.o: N:/Sensores/temperatura/publish/versao1/MAX6675_API.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_RTOS_FREE_RTOS" -D"CPU_MKL25Z128VLK4" -DDEBUG=1 -I"N:/Integracao/KDS/SDK/platform/system/inc" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Integracao/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Integracao/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -I"N:/Integracao/KDS/SDK/platform/osa/inc" -I"N:/Integracao/KDS/SDK/platform/hal/inc" -I"N:/Integracao/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Integracao/KDS/SDK/platform/CMSIS/Include" -I"N:/Integracao/KDS/SDK/platform/devices" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Integracao/KDS/SDK/platform/utilities/src" -I"N:/Integracao/KDS/SDK/platform/utilities/inc" -I"N:/Integracao/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Integracao/KDS/Sources" -I"N:/Integracao/KDS/Generated_Code" -I"N:/Integracao/KDS/SDK/platform/drivers/inc" -I"N:\Integracao\Prova_Conceito\Tarefas" -I"N:\Integracao\Prova_Conceito\Template" -I"N:\Radio\publish\versao5" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


