################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CXX_SRCS += \
../src/commands.cxx \
../src/files.cxx \
../src/flags.cxx \
../src/interface.cxx \
../src/keys.cxx \
../src/main.cxx \
../src/menus.cxx \
../src/screen.cxx \
../src/style.cxx \
../src/sys.cxx 

CXX_DEPS += \
./src/commands.d \
./src/files.d \
./src/flags.d \
./src/interface.d \
./src/keys.d \
./src/main.d \
./src/menus.d \
./src/screen.d \
./src/style.d \
./src/sys.d 

OBJS += \
./src/commands.o \
./src/files.o \
./src/flags.o \
./src/interface.o \
./src/keys.o \
./src/main.o \
./src/menus.o \
./src/screen.o \
./src/style.o \
./src/sys.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cxx
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/anuj/eclipse-workspace/jobseeker/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


