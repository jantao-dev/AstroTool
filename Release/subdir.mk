################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../class.application.cpp \
../class.battery.cpp \
../class.display.cpp \
../class.drive.cpp \
../class.interval.cpp \
../class.keyboard.cpp \
../class.shutter.cpp \
../main.cpp 

OBJS += \
./class.application.o \
./class.battery.o \
./class.display.o \
./class.drive.o \
./class.interval.o \
./class.keyboard.o \
./class.shutter.o \
./main.o 

CPP_DEPS += \
./class.application.d \
./class.battery.d \
./class.display.d \
./class.drive.d \
./class.interval.d \
./class.keyboard.d \
./class.shutter.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega8 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


