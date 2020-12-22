#include "Driver.hpp"

#include <main.h>
#include <gpio.h>

void Foo::Driver::Initalize()
{
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
}