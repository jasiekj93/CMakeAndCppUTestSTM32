#pragma once

#include <libFoo/Application/ILed.hpp>

namespace Foo::Driver
{
    class Led : public Application::ILed
    {
    public:
        enum Color
        {
            Red,
            Green,
            Blue,

            Count
        };

        static Led * GetInstance(Color);

        void Set(bool) override;
        bool Get() override;
        void Toggle() override;

    protected:
        Led(Color);

    private:
        static Led leds[Led::Color::Count];

        Color _color;
    };
}