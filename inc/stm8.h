#ifndef STM8_H
#define STM8_H

#include <stdint.h>

/* Core addresses */
#define FLASH_BASE   0x8000

/* Clock */
#define CLK_CKDIVR (*(volatile uint8_t*)0x50C6)

/* GPIO Port B */
#define PB_ODR (*(volatile uint8_t*)0x5005)
#define PB_IDR (*(volatile uint8_t*)0x5006)
#define PB_DDR (*(volatile uint8_t*)0x5007)
#define PB_CR1 (*(volatile uint8_t*)0x5008)
#define PB_CR2 (*(volatile uint8_t*)0x5009)

/* Interrupt enable */
#define enableInterrupts()  __asm__("rim")
#define disableInterrupts() __asm__("sim")

#endif
