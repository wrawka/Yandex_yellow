################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Date.cpp \
../src/main.cpp \
../src/test_runner.cpp \
../src/token.cpp 

OBJS += \
./src/Date.o \
./src/main.o \
./src/test_runner.o \
./src/token.o 

CPP_DEPS += \
./src/Date.d \
./src/main.d \
./src/test_runner.d \
./src/token.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


