#include "stm8_01.h"

void main(void)
{
    CLK_CKDIVR = 0x00; // full speed

    PB_DDR |= (1 << 5);  // PB5 output
    PB_CR1 |= (1 << 5);  // push-pull

    while (1)
    {
        PB_ODR ^= (1 << 5);
        for (volatile long i = 0; i < 100000; i++);
    }
}
