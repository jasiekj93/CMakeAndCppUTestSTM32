#include "Led.hpp"

#include <gpio.h>

using namespace Foo::Driver;

Led Led::leds[Led::Color::Count] = { Led::Red, Led::Green, Led::Blue };

Led * Led::GetInstance(Color color)
{
    if(color >= Color::Count)
        return nullptr;
    else
    {
        return &leds[color];
    }
}

Led::Led(Color color)
    : _color(color)
{
}

void Led::Set(bool value)
{
    GPIO_PinState state = GPIO_PIN_SET;

    if(value == false)
        state = GPIO_PIN_RESET;

    switch (_color)
    {
    case Color::Red:
        return HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, state);
    case Color::Green:
        return HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, state);
    case Color::Blue:
        return HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, state);
    default:
        return;
    }
}

bool Led::Get()
{
    switch (_color)
    {
    case Color::Red:
        return (HAL_GPIO_ReadPin(LD3_GPIO_Port, LD3_Pin) == GPIO_PIN_SET);
    case Color::Green:
        return (HAL_GPIO_ReadPin(LD1_GPIO_Port, LD1_Pin) == GPIO_PIN_SET);
    case Color::Blue:
        return (HAL_GPIO_ReadPin(LD2_GPIO_Port, LD2_Pin) == GPIO_PIN_SET);
    default:
        return false;
    }
}

void Led::Toggle()
{
    switch (_color)
    {
    case Color::Red:
        return HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
    case Color::Green:
        return HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
    case Color::Blue:
        return HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    default:
        return;
    }
}