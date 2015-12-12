################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/CPU/Timer.cpp \
../Source/CPU/auxiliar.cpp 

OBJS += \
./Source/CPU/Timer.o \
./Source/CPU/auxiliar.o 

CPP_DEPS += \
./Source/CPU/Timer.d \
./Source/CPU/auxiliar.d 


# Each subdirectory must supply rules for building sources it contributes
Source/CPU/%.o: ../Source/CPU/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


