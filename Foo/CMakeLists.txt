cmake_minimum_required(VERSION 3.15)
project(Foo VERSION 0.1.0)

enable_language(ASM)

#Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

#Add unit tests to library
#add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

#Set path to source files
set(CORE_SOURCE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/Foo
)

#Build executable
set(EXECUTABLE ${PROJECT_NAME}.elf)

#Add include paths
include_directories(
    ../libFoo-Application
    ../libFoo-Driver
    )

add_executable(${EXECUTABLE}
    ${CORE_SOURCE_PATH}/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/startup_stm32f429xx.s
    )

#Link libraries
target_link_libraries(${EXECUTABLE} PUBLIC
    Foo-Application
    Foo-Driver)

    
target_link_options(${EXECUTABLE} PRIVATE
    -T${CMAKE_CURRENT_SOURCE_DIR}/STM32F429ZITx_FLASH.ld
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -specs=nano.specs
    -specs=nosys.specs
    -lc
    -lm
    -lnosys
    -Wl,-Map=${PROJECT_NAME}.map,--cref
    -Wl,--gc-sections
    -Wl,--print-memory-usage
    -Wl,--no-wchar-size-warning
    )

# Create hex file
add_custom_command(TARGET ${EXECUTABLE}
    POST_BUILD
    COMMAND arm-none-eabi-objcopy -O ihex ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EXECUTABLE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex
    COMMAND arm-none-eabi-objcopy -O binary ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EXECUTABLE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.bin)