#include "Delayer.hpp"

#include <main.h>

using namespace Foo::Driver;

void Delayer::Delay(unsigned int ms)
{
    HAL_Delay(ms);
}