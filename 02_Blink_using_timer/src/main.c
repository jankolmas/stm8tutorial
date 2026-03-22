#include "led.h"
#include "timing.h"

void TIM1_interrupt(void) __interrupt(TIM1_INTERRUPT_VECTOR)
{
    timing_handle_interrupt();
}

void main(void)
{
    full_speed_clock();
    setup_onboard_led();
    timing_init();

    __asm__("rim");       // enable interrupts

    while (1)
    {
        sleep_ms(1000);
        toggle_onboard_led();
    }
}
