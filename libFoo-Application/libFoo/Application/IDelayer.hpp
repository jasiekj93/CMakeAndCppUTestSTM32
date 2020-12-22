#pragma once

namespace Foo::Application
{
    class IDelayer
    {
    public:
        virtual ~IDelayer() {}

        virtual void Delay(unsigned int ms) = 0;
    };
}