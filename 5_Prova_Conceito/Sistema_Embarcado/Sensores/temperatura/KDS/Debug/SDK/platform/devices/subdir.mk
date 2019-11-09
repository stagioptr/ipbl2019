################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/devices/startup.c 

OBJS += \
./SDK/platform/devices/startup.o 

C_DEPS += \
./SDK/platform/devices/startup.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/devices/%.o: ../SDK/platform/devices/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL25Z128VLK4" -I"N:/Sensores/temperatura/KDS/SDK/platform/hal/inc" -I"N:/Sensores/temperatura/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Sensores/temperatura/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Sensores/temperatura/KDS/SDK/platform/system/inc" -I"N:/Sensores/temperatura/KDS/SDK/platform/osa/inc" -I"N:/Sensores/temperatura/KDS/SDK/platform/CMSIS/Include" -I"N:/Sensores/temperatura/KDS/SDK/platform/devices" -I"N:/Sensores/temperatura/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Sensores/temperatura/KDS/SDK/platform/utilities/src" -I"N:/Sensores/temperatura/KDS/SDK/platform/utilities/inc" -I"N:/Sensores/temperatura/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Sensores/temperatura/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Sensores/temperatura/KDS/Sources" -I"N:/Sensores/temperatura/KDS/Generated_Code" -I"N:/Sensores/temperatura/KDS/SDK/platform/drivers/inc" -I"N:/Sensores/temperatura/KDS/../driver_code" -I"N:/Sensores/temperatura/KDS/../driver_code/Template" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


