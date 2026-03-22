#include "led.h"

void main(void)
{
    setup_onboard_led();

    while (1)
    {
        toggle_onboard_led();
        for (volatile long i = 0; i < 10000; i++);
    }
}
