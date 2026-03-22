#include "led.h"
#include "timing.h"
#include <stddef.h>

volatile uint32_t system_ms = 0;

void timing_handle_interrupt(void)
{
    TIM1_SR1 &= ~0x01;  // clear update flag
    system_ms++;
}

void timing_init()
{
    // Setup TIM1
    // Prescaler registers (high and low bytes). 
    // Together they set the clock division factor.
    // Value 0x000F (16) divides the 16 MHz clock by 16 to get 1 MHz.
    TIM1_PSCRH = 0x00;
    TIM1_PSCRL = 0x0F;    
    
    // Auto-Reload Register (high and low bytes).
    // Sets the period/maximum count value. When the counter reaches this value
    // (1000 = 0x03E8), it resets to 0 and generates an update interrupt.
    TIM1_ARRH = 0x03;     
    TIM1_ARRL = 0xE8;
    
    // Enable update interrupt
    TIM1_IER |= 0x01;
    
    // Enable counter
    TIM1_CR1 |= 0x01;
}

void full_speed_clock(void)
{
    CLK_CKDIVR = 0x00;  // full speed (16 MHz)
}

void sleep_ms(uint32_t delay)
{
    uint32_t start = system_ms;

    while (system_ms - start < delay) {
        // Blocking until time is up
    }
}