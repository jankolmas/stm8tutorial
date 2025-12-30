#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

void eeprom_write_byte(uint8_t address, uint8_t data);
uint8_t eeprom_read_byte(uint8_t address);

#endif // EEPROM_H