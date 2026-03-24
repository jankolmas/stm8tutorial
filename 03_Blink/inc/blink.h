#ifndef BLINK_H
#define BLINK_H

#define SHORT_BLINK_MS 150
#define LONG_BLINK_MS 500
#define SHORT_DELAY_MS 200
#define LONG_DELAY_MS 2000

void short_blink(void);
void long_blink(void);
void pause_blink(void);
void blink_n_times(uint8_t n);

#endif //BLINK_H
