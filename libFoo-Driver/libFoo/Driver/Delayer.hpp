#pragma once

#include <libFoo/Application/IDelayer.hpp>

namespace Foo::Driver
{
    class Delayer : public Application::IDelayer
    {
    public:
        void Delay(unsigned int ms) override;
    };
}