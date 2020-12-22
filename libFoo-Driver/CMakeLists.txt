cmake_minimum_required(VERSION 3.15)
project(Foo-Driver VERSION 0.1.0)

enable_language(C ASM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(STM32CUBEMX_SOURCES
        Cube/Src/main.c 
        Cube/Src/gpio.c 
        Cube/Src/stm32f4xx_it.c 
        Cube/Src/stm32f4xx_hal_msp.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c 
        Cube/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c 
        Cube/Src/system_stm32f4xx.c

        #Cube/startup_stm32f429xx.s
        )

set(SOURCES
    libFoo/Driver/Delayer.cpp
    libFoo/Driver/Driver.cpp
    libFoo/Driver/Led.cpp
    )

include_directories(${PROJECT_NAME}
    Cube/Inc
    Cube/Drivers/STM32F4xx_HAL_Driver/Inc
    Cube/Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Cube/Drivers/CMSIS/Include

    ../libFoo-Application
    
    libFoo/Driver
    )

add_definitions(
    -DUSE_HAL_DRIVER
    -DSTM32F429xx
    )

add_library(${PROJECT_NAME} ${SOURCES} ${STM32CUBEMX_SOURCES})



