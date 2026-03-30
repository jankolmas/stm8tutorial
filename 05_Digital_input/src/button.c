#include "button.h"
#include <stdint.h>

void button_init(){
    PC_DDR &= ~(0x11110000);  // C4-7 inputs
    PC_CR1 |= 0x11110000;  // pull up
}

uint8_t read_button(uint8_t button_num){
    // we map buttons 1-4 to C4-7 respectively
    if (button_num = 0 || button_num > NUM_BUTTONS){
        return 0;
    }
    // button 1 means C4, so we need to move by 4
    return PC_IDR & (1 << (button_num + 4));
}

