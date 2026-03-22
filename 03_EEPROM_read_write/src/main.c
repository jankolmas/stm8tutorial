#include "led.h"
#include "timing.h"
#include "eeprom.h"

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

    uint8_t i = read_eeprom();
    blink_n_times(i);

    while(1)
    {
        //end program
    }
}
