################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/condition_parser.cpp \
../src/condition_parser_test.cpp \
../src/finals.cpp \
../src/main.cpp \
../src/token.cpp 

OBJS += \
./src/condition_parser.o \
./src/condition_parser_test.o \
./src/finals.o \
./src/main.o \
./src/token.o 

CPP_DEPS += \
./src/condition_parser.d \
./src/condition_parser_test.d \
./src/finals.d \
./src/main.d \
./src/token.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


