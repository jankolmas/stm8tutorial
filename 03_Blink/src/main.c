#include "blink.h"
#include "time.h"

void TIM1_interrupt(void) __interrupt(TIM1_INTERRUPT_VECTOR)
{
    tim1_handle_interrupt();
}

void main(void)
{
    blink_init();

    __asm__("rim");       // enable interrupts
    
    // Morse for S: ...
    short_blink();
    short_blink();
    short_blink();
    pause_blink();
    
    // Morse for T: -
    long_blink();
    pause_blink();
    
    // Morse for M: --
    long_blink();
    long_blink();
    pause_blink();

    while(1)
    {
         __asm__("wfi");  // low power mode
    }
}
