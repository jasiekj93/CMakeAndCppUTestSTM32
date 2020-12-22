set(CMAKE_TOOLCHAIN_FILE arm-none-eabi-gcc.cmake)

cmake_minimum_required(VERSION 3.15)
project(Foo_Solution)

#find doxygen to create documentation
find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()

#set path to output files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_compile_options(
        -mcpu=cortex-m4
        -mthumb
        -mfpu=fpv4-sp-d16
        -mfloat-abi=hard
    
        -fdata-sections
        -ffunction-sections
    
        -Wall
    
        $<$<CONFIG:Debug>:-Og>
  )

#Add subdirectories to your projects
add_subdirectory(libFoo-Driver)
add_subdirectory(libFoo-Application)
add_subdirectory(Foo)


