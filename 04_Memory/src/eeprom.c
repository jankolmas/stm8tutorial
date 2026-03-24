#include "eeprom.h"

uint8_t read_eeprom(void)
{
    return *EEPROM_TEST_ADDRESS;
}
