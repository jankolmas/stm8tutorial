#include "led.h"
#include "timing.h"

void main(void)
{
    full_speed_clock();
    setup_onboard_led();

    // Initialize timer with blink callback
    timing_init(toggle_onboard_led);

    __asm__("rim");       // enable interrupts

    while (1)
    {
        // main loop idle
    }
}
