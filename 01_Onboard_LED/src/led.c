#include "led.h"

void setup_onboard_led(void)
{
    PB_DDR |= (1 << 5);  // PB5 output
    PB_CR1 |= (1 << 5);  // push-pull
}

void toggle_onboard_led(void)
{
    PB_ODR ^= (1 << 5);
}
