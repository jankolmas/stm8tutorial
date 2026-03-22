#ifndef LED_H
#define LED_H

#include <stdint.h>

/* GPIO Port B */
#define PB_ODR (*(volatile uint8_t*)0x5005)
#define PB_DDR (*(volatile uint8_t*)0x5007)
#define PB_CR1 (*(volatile uint8_t*)0x5008)

#define DEFAULT_LED_ON_MS 150
#define DEFAULT_LED_OFF_MS 200

void setup_onboard_led(void);
void toggle_onboard_led(void);
void onboard_led_on(void);
void onboard_led_off(void);
void blink(uint32_t on_ms, uint32_t off_ms);
void blink_n_times(int n);

#endif
