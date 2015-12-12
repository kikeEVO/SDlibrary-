################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/stream/Print.cpp \
../Source/stream/Stream.cpp 

OBJS += \
./Source/stream/Print.o \
./Source/stream/Stream.o 

CPP_DEPS += \
./Source/stream/Print.d \
./Source/stream/Stream.d 


# Each subdirectory must supply rules for building sources it contributes
Source/stream/%.o: ../Source/stream/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


