#include "blink.h"
#include "time.h"
#include "button.h"
#include "led.h"

void TIM1_interrupt(void) __interrupt(TIM1_INTERRUPT_VECTOR)
{
    tim1_handle_interrupt();
}

void main(void)
{
    blink_init();
    button_init();

    __asm__("rim");       // enable interrupts

    uint8_t button_pressed = 0;
    
    blink_n_times(2);
    sleep_ms(1000);
    

    while(1)
    {
        
        //go through all buttons
        for(int i = 1; i <= NUM_BUTTONS; i++){
            // read digital pin
            button_pressed = read_button(i);
            
            if (button_pressed > 0) {
                blink_n_times(i);
            } 
            sleep_ms(10);
        }

    }
}
