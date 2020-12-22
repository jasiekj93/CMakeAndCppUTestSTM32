#pragma once

namespace Foo::Application
{
    class ILed
    {
    public:
        virtual ~ILed() {}

        virtual void Set(bool) = 0;
        virtual bool Get() = 0;
        virtual void Toggle() = 0;
    };
}