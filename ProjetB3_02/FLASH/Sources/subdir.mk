################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/I2C.c" \
"../Sources/RF.c" \
"../Sources/bsp.c" \
"../Sources/centrale.c" \
"../Sources/main.c" \
"../Sources/monSPI.c" \
"../Sources/mon_SPI.c" \
"../Sources/optical.c" \

C_SRCS += \
../Sources/I2C.c \
../Sources/RF.c \
../Sources/bsp.c \
../Sources/centrale.c \
../Sources/main.c \
../Sources/monSPI.c \
../Sources/mon_SPI.c \
../Sources/optical.c \

OBJS += \
./Sources/I2C_c.obj \
./Sources/RF_c.obj \
./Sources/bsp_c.obj \
./Sources/centrale_c.obj \
./Sources/main_c.obj \
./Sources/monSPI_c.obj \
./Sources/mon_SPI_c.obj \
./Sources/optical_c.obj \

OBJS_QUOTED += \
"./Sources/I2C_c.obj" \
"./Sources/RF_c.obj" \
"./Sources/bsp_c.obj" \
"./Sources/centrale_c.obj" \
"./Sources/main_c.obj" \
"./Sources/monSPI_c.obj" \
"./Sources/mon_SPI_c.obj" \
"./Sources/optical_c.obj" \

C_DEPS += \
./Sources/I2C_c.d \
./Sources/RF_c.d \
./Sources/bsp_c.d \
./Sources/centrale_c.d \
./Sources/main_c.d \
./Sources/monSPI_c.d \
./Sources/mon_SPI_c.d \
./Sources/optical_c.d \

C_DEPS_QUOTED += \
"./Sources/I2C_c.d" \
"./Sources/RF_c.d" \
"./Sources/bsp_c.d" \
"./Sources/centrale_c.d" \
"./Sources/main_c.d" \
"./Sources/monSPI_c.d" \
"./Sources/mon_SPI_c.d" \
"./Sources/optical_c.d" \

OBJS_OS_FORMAT += \
./Sources/I2C_c.obj \
./Sources/RF_c.obj \
./Sources/bsp_c.obj \
./Sources/centrale_c.obj \
./Sources/main_c.obj \
./Sources/monSPI_c.obj \
./Sources/mon_SPI_c.obj \
./Sources/optical_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/I2C_c.obj: ../Sources/I2C.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/I2C.args" -ObjN="Sources/I2C_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/RF_c.obj: ../Sources/RF.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/RF.args" -ObjN="Sources/RF_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/bsp_c.obj: ../Sources/bsp.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/bsp.args" -ObjN="Sources/bsp_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/centrale_c.obj: ../Sources/centrale.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/centrale.args" -ObjN="Sources/centrale_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/monSPI_c.obj: ../Sources/monSPI.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/monSPI.args" -ObjN="Sources/monSPI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/mon_SPI_c.obj: ../Sources/mon_SPI.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/mon_SPI.args" -ObjN="Sources/mon_SPI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/optical_c.obj: ../Sources/optical.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/optical.args" -ObjN="Sources/optical_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


