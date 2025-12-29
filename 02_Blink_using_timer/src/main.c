#include "stm8_02.h"

volatile uint16_t timer_count = 0;

// TIM1 interrupt handler
void TIM1_interrupt(void) __interrupt(TIM1_INTERRUPT_VECTOR)
{
    TIM1_SR1 &= ~0x01;  // clear update flag
    
    timer_count++;
    if (timer_count >= 1000)  // 1000ms = 1s
    {
        PB_ODR ^= (1 << 5);  // toggle LED
        timer_count = 0;
    }
}

void main(void)
{
    CLK_CKDIVR = 0x00;  // full speed (16 MHz)

    // Setup GPIO
    PB_DDR |= (1 << 5);   // PB5 output
    PB_CR1 |= (1 << 5);   // push-pull

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

    __asm__("rim");       // enable interrupts

    while (1)
    {
        // main loop idle
    }
}
