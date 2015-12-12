################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/SD/File.cpp \
../Source/SD/SD.cpp 

OBJS += \
./Source/SD/File.o \
./Source/SD/SD.o 

CPP_DEPS += \
./Source/SD/File.d \
./Source/SD/SD.d 


# Each subdirectory must supply rules for building sources it contributes
Source/SD/%.o: ../Source/SD/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


