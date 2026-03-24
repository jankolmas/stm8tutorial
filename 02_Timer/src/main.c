#include "led.h"
#include "time.h"

void TIM1_interrupt(void) __interrupt(TIM1_INTERRUPT_VECTOR)
{
    tim1_handle_interrupt();
}

void main(void)
{
    onboard_led_init();
    time_init();

    while(1)
    {
        toggle_onboard_led();
        sleep_ms(500);
    }
}
