#include "led.h"

void onboard_led_init(void)
{
    PB_DDR |= (1 << 5);  // PB5 output
    PB_CR1 |= (1 << 5);  // push-pull
}

void onboard_led_on(void)
{
    PB_ODR &= ~(1 << 5);
}

void onboard_led_off(void)
{
    PB_ODR |= (1 << 5);
}

void onboard_led_toggle(void)
{
    PB_ODR ^= (1 << 5);
}
