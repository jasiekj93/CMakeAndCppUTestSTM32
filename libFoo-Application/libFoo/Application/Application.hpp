#pragma once

#include <cstddef>

#include <libFoo/Application/IDelayer.hpp>
#include <libFoo/Application/ILed.hpp>

namespace Foo::Application
{
    int Run(ILed *leds[], size_t, IDelayer &);
}