#include "stm8.h"

volatile uint16_t timer_count = 0;

// TIM1 interrupt handler
void TIM1_UPD_OVF_IRQHandler(void) __interrupt(11)
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
    // For 1ms interrupt: prescaler = 16, period = 1000
    // Clock = 16 MHz, prescaler = 16 -> 1 MHz, 1000 counts = 1ms
    TIM1_PSCRH = 0x00;
    TIM1_PSCRL = 0x0F;    // prescaler = 16
    
    TIM1_ARRH = 0x03;     // auto-reload = 1000
    TIM1_ARRL = 0xE8;
    
    TIM1_IER |= 0x01;     // enable update interrupt
    TIM1_CR1 |= 0x01;     // enable counter

    __asm__("rim");       // enable interrupts

    while (1)
    {
        // main loop idle
    }
}
