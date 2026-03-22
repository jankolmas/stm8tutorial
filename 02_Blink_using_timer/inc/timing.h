#ifndef TIMING_H
#define TIMING_H

#include <stdint.h>

/* Clock */
#define CLK_CKDIVR (*(volatile uint8_t*)0x50C6)

/* TIM1 */
#define TIM1_CR1 (*(volatile uint8_t*)0x5250)
#define TIM1_IER (*(volatile uint8_t*)0x5254)
#define TIM1_SR1 (*(volatile uint8_t*)0x5255)
#define TIM1_CNTRH (*(volatile uint8_t*)0x526E)
#define TIM1_CNTRL (*(volatile uint8_t*)0x526F)
#define TIM1_PSCRH (*(volatile uint8_t*)0x5260)
#define TIM1_PSCRL (*(volatile uint8_t*)0x5261)
#define TIM1_ARRH (*(volatile uint8_t*)0x5262)
#define TIM1_ARRL (*(volatile uint8_t*)0x5263)
#define TIM1_INTERRUPT_VECTOR 11

typedef void (*timer_callback_t)(void);

void timing_handle_interrupt(void);

/**
 * Initialize the timer with the given callback function.
 * The callback will be called periodically based on the timer configuration.
 * 
 * @param callback Function to be called on each timer interrupt
 */
void timing_init(timer_callback_t callback);

void full_speed_clock(void);

#endif // TIMING_H
