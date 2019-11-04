################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/rtos/FreeRTOS/src/croutine.c \
../SDK/rtos/FreeRTOS/src/event_groups.c \
../SDK/rtos/FreeRTOS/src/heap_1.c \
../SDK/rtos/FreeRTOS/src/heap_2.c \
../SDK/rtos/FreeRTOS/src/heap_3.c \
../SDK/rtos/FreeRTOS/src/heap_4.c \
../SDK/rtos/FreeRTOS/src/heap_5.c \
../SDK/rtos/FreeRTOS/src/list.c \
../SDK/rtos/FreeRTOS/src/queue.c \
../SDK/rtos/FreeRTOS/src/tasks.c \
../SDK/rtos/FreeRTOS/src/timers.c 

OBJS += \
./SDK/rtos/FreeRTOS/src/croutine.o \
./SDK/rtos/FreeRTOS/src/event_groups.o \
./SDK/rtos/FreeRTOS/src/heap_1.o \
./SDK/rtos/FreeRTOS/src/heap_2.o \
./SDK/rtos/FreeRTOS/src/heap_3.o \
./SDK/rtos/FreeRTOS/src/heap_4.o \
./SDK/rtos/FreeRTOS/src/heap_5.o \
./SDK/rtos/FreeRTOS/src/list.o \
./SDK/rtos/FreeRTOS/src/queue.o \
./SDK/rtos/FreeRTOS/src/tasks.o \
./SDK/rtos/FreeRTOS/src/timers.o 

C_DEPS += \
./SDK/rtos/FreeRTOS/src/croutine.d \
./SDK/rtos/FreeRTOS/src/event_groups.d \
./SDK/rtos/FreeRTOS/src/heap_1.d \
./SDK/rtos/FreeRTOS/src/heap_2.d \
./SDK/rtos/FreeRTOS/src/heap_3.d \
./SDK/rtos/FreeRTOS/src/heap_4.d \
./SDK/rtos/FreeRTOS/src/heap_5.d \
./SDK/rtos/FreeRTOS/src/list.d \
./SDK/rtos/FreeRTOS/src/queue.d \
./SDK/rtos/FreeRTOS/src/tasks.d \
./SDK/rtos/FreeRTOS/src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/rtos/FreeRTOS/src/%.o: ../SDK/rtos/FreeRTOS/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -D"FSL_RTOS_FREE_RTOS" -I"N:/Radio/KDS/SDK/platform/hal/inc" -I"N:/Radio/KDS/SDK/platform/hal/src/sim/MKL25Z4" -I"N:/Radio/KDS/SDK/platform/system/src/clock/MKL25Z4" -I"N:/Radio/KDS/SDK/platform/system/inc" -I"N:/Radio/KDS/SDK/platform/osa/inc" -I"N:/Radio/KDS/SDK/platform/CMSIS/Include" -I"N:/Radio/KDS/SDK/platform/devices" -I"N:/Radio/KDS/SDK/platform/devices/MKL25Z4/include" -I"N:/Radio/KDS/SDK/platform/utilities/src" -I"N:/Radio/KDS/SDK/platform/utilities/inc" -I"N:/Radio/KDS/SDK/platform/devices/MKL25Z4/startup" -I"N:/Radio/KDS/Generated_Code/SDK/platform/devices/MKL25Z4/startup" -I"N:/Radio/KDS/Sources" -I"N:/Radio/KDS/Generated_Code" -I"N:/Radio/KDS/SDK/platform/drivers/inc" -I"N:/Radio/KDS/../driver_code" -I"N:/Radio/KDS/../driver_code/Template" -I"N:/Radio/KDS/SDK/rtos/FreeRTOS/include" -I"N:/Radio/KDS/SDK/rtos/FreeRTOS/port/gcc" -I"N:/Radio/KDS/Generated_Code/SDK/rtos/FreeRTOS/config" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


