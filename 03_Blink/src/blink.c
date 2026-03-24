#include "led.h"
#include "time.h"

void blink_init()
{
	onboard_led_init();
	time_init();
}

void short_blink()
{
	onboard_led_on();
	sleep_ms(SHORT_BLINK_MS);
	onboard_led_off();
	sleep_ms(SHORT_DELAY_MS);
}

void long_blink()
{
	onboard_led_on();
	sleep_ms(LONG_BLINK_MS);
	onboard_led_off();
	sleep_ms(SHORT_DELAY_MS);
}

void pause_blink()
{
	sleep_ms(LONG_DELAY_MS);
}

void blink_n_times(uint8_t n)
{
    for (uint8_t i = 0; i < n; i++){
        short_blink();
    }
}
