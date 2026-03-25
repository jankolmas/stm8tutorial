#include "led.h"

void main(void)
{
    onboard_led_init();

    while (1)
    {
        onboard_led_toggle();
        for (volatile long i = 0; i < 10000; i++);
    }
}
