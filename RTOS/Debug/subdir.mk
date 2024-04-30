################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_cfg.c \
../DIO_prg.c \
../RTOS_cfg.c \
../RTOS_prg.c \
../main.c 

OBJS += \
./DIO_cfg.o \
./DIO_prg.o \
./RTOS_cfg.o \
./RTOS_prg.o \
./main.o 

C_DEPS += \
./DIO_cfg.d \
./DIO_prg.d \
./RTOS_cfg.d \
./RTOS_prg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


