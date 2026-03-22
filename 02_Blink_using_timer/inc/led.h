#ifndef LED_H
#define LED_H

#include <stdint.h>

/* GPIO Port B */
#define PB_ODR (*(volatile uint8_t*)0x5005)
#define PB_DDR (*(volatile uint8_t*)0x5007)
#define PB_CR1 (*(volatile uint8_t*)0x5008)

void setup_onboard_led(void);
void toggle_onboard_led(void);
void onboard_led_on(void);
void onboard_led_off(void);
void blink(uint32_t on_ms, uint32_t off_ms);

#endif
