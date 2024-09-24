################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lab1_Lib/LAb1_Ex6to10.c 

OBJS += \
./Core/Src/Lab1_Lib/LAb1_Ex6to10.o 

C_DEPS += \
./Core/Src/Lab1_Lib/LAb1_Ex6to10.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lab1_Lib/%.o: ../Core/Src/Lab1_Lib/%.c Core/Src/Lab1_Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Documents/DaiHoc/HK241/VXL_MCU/Labs/Lab1/Lab1_GIT/Lab1_Src/Core/Src/Lab1_Lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

