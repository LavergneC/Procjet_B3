################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/PTA.c" \
"../Generated_Code/SCI.c" \
"../Generated_Code/SPI.c" \
"../Generated_Code/TPM1.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/IO_Map.c \
../Generated_Code/PTA.c \
../Generated_Code/SCI.c \
../Generated_Code/SPI.c \
../Generated_Code/TPM1.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/PTA_c.obj \
./Generated_Code/SCI_c.obj \
./Generated_Code/SPI_c.obj \
./Generated_Code/TPM1_c.obj \
./Generated_Code/Vectors_c.obj \

OBJS_QUOTED += \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/PTA_c.obj" \
"./Generated_Code/SCI_c.obj" \
"./Generated_Code/SPI_c.obj" \
"./Generated_Code/TPM1_c.obj" \
"./Generated_Code/Vectors_c.obj" \

C_DEPS += \
./Generated_Code/Cpu_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/PTA_c.d \
./Generated_Code/SCI_c.d \
./Generated_Code/SPI_c.d \
./Generated_Code/TPM1_c.d \
./Generated_Code/Vectors_c.d \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/PTA_c.d" \
"./Generated_Code/SCI_c.d" \
"./Generated_Code/SPI_c.d" \
"./Generated_Code/TPM1_c.d" \
"./Generated_Code/Vectors_c.d" \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/PTA_c.obj \
./Generated_Code/SCI_c.obj \
./Generated_Code/SPI_c.obj \
./Generated_Code/TPM1_c.obj \
./Generated_Code/Vectors_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Cpu.args" -ObjN="Generated_Code/Cpu_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/IO_Map.args" -ObjN="Generated_Code/IO_Map_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PTA_c.obj: ../Generated_Code/PTA.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/PTA.args" -ObjN="Generated_Code/PTA_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SCI_c.obj: ../Generated_Code/SCI.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/SCI.args" -ObjN="Generated_Code/SCI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SPI_c.obj: ../Generated_Code/SPI.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/SPI.args" -ObjN="Generated_Code/SPI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TPM1_c.obj: ../Generated_Code/TPM1.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/TPM1.args" -ObjN="Generated_Code/TPM1_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Generated_Code/Vectors.args" -ObjN="Generated_Code/Vectors_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


