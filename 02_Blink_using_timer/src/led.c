#include "led.h"
#include "timing.h"

void setup_onboard_led(void)
{
    PB_DDR |= (1 << 5);  // PB5 output
    PB_CR1 |= (1 << 5);  // push-pull
}

void toggle_onboard_led(void)
{
    PB_ODR ^= (1 << 5);
}

void onboard_led_on(void)
{
    PB_ODR &= ~(1 << 5);
}

void onboard_led_off(void)
{
    PB_ODR |= (1 << 5);
}

void blink(uint32_t on_ms, uint32_t off_ms)
{
    onboard_led_on();
    sleep_ms(on_ms);
    onboard_led_off();
    sleep_ms(off_ms);
}
