#include <libFoo/Application/Application.hpp>
#include <libFoo/Driver/Led.hpp>
#include <libFoo/Driver/Delayer.hpp>
#include <libFoo/Driver/Driver.hpp>

using namespace Foo;

int main(int argc, const char *argv[])
{
    Driver::Initalize();

    Application::ILed *leds[Driver::Led::Count];

    leds[0] = Driver::Led::GetInstance(Driver::Led::Red);
    leds[1] = Driver::Led::GetInstance(Driver::Led::Green);
    leds[2] = Driver::Led::GetInstance(Driver::Led::Blue);

    Driver::Delayer delayer;

    return Foo::Application::Run(leds, Driver::Led::Count, delayer);
}