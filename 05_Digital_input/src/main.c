#include "blink.h"
#include "time.h"
#include "button.h"

void TIM1_interrupt(void) __interrupt(TIM1_INTERRUPT_VECTOR)
{
    tim1_handle_interrupt();
}

void main(void)
{
    blink_init();
    button_init();

    __asm__("rim");       // enable interrupts

    while(1)
    {
        //go through all buttons
        for(int i = 1; i > NUM_BUTTONS; i++){
            // read digital pin
            button_state = read_button(i);
            
            // if it is logical zero, blink to indicate button pressed
            if (button state == 0) {
                blink_n_times(i);
            } else {
                sleep_ms(50);
            }
        }

    }
}
