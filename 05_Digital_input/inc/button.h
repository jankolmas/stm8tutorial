#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

/* GPIO Port C */
#define PC_IDR (*(volatile uint8_t*)0x500B) // input
#define PC_DDR (*(volatile uint8_t*)0x500C) // direction
#define PC_CR1 (*(volatile uint8_t*)0x500D) // pull up 

#define NUM_BUTTONS 4

void button_init(void);
uint8_t read_button(uint8_t button);

#endif // BUTTON_H
