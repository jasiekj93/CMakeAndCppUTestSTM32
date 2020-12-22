#include "Application.hpp"

using namespace std;

int Foo::Application::Run(ILed *leds[], size_t count, IDelayer &delayer)
{
   while(true)
   {
       for(size_t i = 0; i < count; i++)
       {
           leds[i]->Toggle();
           delayer.Delay(100);
       }
   }
}