################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/system/src/interrupt/fsl_interrupt_manager.c 

OBJS += \
./SDK/platform/system/src/interrupt/fsl_interrupt_manager.o 

C_DEPS += \
./SDK/platform/system/src/interrupt/fsl_interrupt_manager.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/system/src/interrupt/%.o: ../SDK/platform/system/src/interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL25Z128VLK4" -I"N:/Sensores/acelerometro/KDS/SDK/platform/hal/inc" -I"N:/Sensores/acelerometro/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Sensores/acelerometro/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Sensores/acelerometro/KDS/SDK/platform/system/inc" -I"N:/Sensores/acelerometro/KDS/SDK/platform/osa/inc" -I"N:/Sensores/acelerometro/KDS/SDK/platform/CMSIS/Include" -I"N:/Sensores/acelerometro/KDS/SDK/platform/devices" -I"N:/Sensores/acelerometro/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Sensores/acelerometro/KDS/SDK/platform/utilities/src" -I"N:/Sensores/acelerometro/KDS/SDK/platform/utilities/inc" -I"N:/Sensores/acelerometro/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Sensores/acelerometro/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Sensores/acelerometro/KDS/Sources" -I"N:/Sensores/acelerometro/KDS/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


