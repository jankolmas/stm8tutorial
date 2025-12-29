#ifndef STM8_H
#define STM8_H

#include <stdint.h>

/* Clock */
#define CLK_CKDIVR (*(volatile uint8_t*)0x50C6)

/* GPIO Port B */
#define PB_ODR (*(volatile uint8_t*)0x5005)
#define PB_DDR (*(volatile uint8_t*)0x5007)
#define PB_CR1 (*(volatile uint8_t*)0x5008)

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

#endif