################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/DbgCs1.c \
../Generated_Code/MainTask.c \
../Generated_Code/Radio1.c \
../Generated_Code/Radio2.c \
../Generated_Code/TaskRadio1.c \
../Generated_Code/TaskRadio2.c \
../Generated_Code/clockMan1.c \
../Generated_Code/free_rtos.c \
../Generated_Code/gpio1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_init.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/DbgCs1.o \
./Generated_Code/MainTask.o \
./Generated_Code/Radio1.o \
./Generated_Code/Radio2.o \
./Generated_Code/TaskRadio1.o \
./Generated_Code/TaskRadio2.o \
./Generated_Code/clockMan1.o \
./Generated_Code/free_rtos.o \
./Generated_Code/gpio1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_init.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/DbgCs1.d \
./Generated_Code/MainTask.d \
./Generated_Code/Radio1.d \
./Generated_Code/Radio2.d \
./Generated_Code/TaskRadio1.d \
./Generated_Code/TaskRadio2.d \
./Generated_Code/clockMan1.d \
./Generated_Code/free_rtos.d \
./Generated_Code/gpio1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_init.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_FREE_RTOS" -I"N:/Radio/KDS/SDK/platform/hal/inc" -I"N:/Radio/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Radio/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Radio/KDS/SDK/platform/system/inc" -I"N:/Radio/KDS/SDK/platform/osa/inc" -I"N:/Radio/KDS/SDK/platform/CMSIS/Include" -I"N:/Radio/KDS/SDK/platform/devices" -I"N:/Radio/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Radio/KDS/SDK/platform/utilities/src" -I"N:/Radio/KDS/SDK/platform/utilities/inc" -I"N:/Radio/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Radio/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Radio/KDS/Sources" -I"N:/Radio/KDS/Generated_Code" -I"N:/Radio/KDS/SDK/platform/drivers/inc" -I"N:/Radio/KDS/../driver_code" -I"N:/Radio/KDS/../driver_code/Template" -I"N:/Radio/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Radio/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Radio/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


