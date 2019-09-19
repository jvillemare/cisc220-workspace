################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Book.cpp \
../Main.cpp \
../SLL.cpp \
../SNode.cpp 

OBJS += \
./Book.o \
./Main.o \
./SLL.o \
./SNode.o 

CPP_DEPS += \
./Book.d \
./Main.d \
./SLL.d \
./SNode.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


