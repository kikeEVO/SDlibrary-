################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/SD/utility/Sd2Card.cpp \
../Source/SD/utility/SdFile.cpp \
../Source/SD/utility/SdVolume.cpp 

OBJS += \
./Source/SD/utility/Sd2Card.o \
./Source/SD/utility/SdFile.o \
./Source/SD/utility/SdVolume.o 

CPP_DEPS += \
./Source/SD/utility/Sd2Card.d \
./Source/SD/utility/SdFile.d \
./Source/SD/utility/SdVolume.d 


# Each subdirectory must supply rules for building sources it contributes
Source/SD/utility/%.o: ../Source/SD/utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


