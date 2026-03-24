#include "blink.h"
#include "time.h"
#include "eeprom.h"

void TIM1_interrupt(void) __interrupt(TIM1_INTERRUPT_VECTOR)
{
    tim1_handle_interrupt();
}

void main(void)
{
    blink_init();

    __asm__("rim");       // enable interrupts

    uint8_t value = read_eeprom();
    blink_n_times(value);

    while(1)
    {
        //end program
    }
}
