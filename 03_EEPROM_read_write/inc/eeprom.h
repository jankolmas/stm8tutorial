#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

#define FLASH_IAPSR (*(volatile uint8_t*)0x505F)
#define FLASH_DUKR (*(volatile uint8_t*)0x5064)
#define FLASH_CR2 (*(volatile uint8_t*)0x505B)
#define FLASH_NCR2 (*(volatile uint8_t*)0x505C)

#define FLASH_IAPSR_DUL 0x08
#define FLASH_CR2_WPRG 0x40

#define EEPROM_TEST_ADDRESS ((volatile uint8_t*)0x4000)

uint8_t read_eeprom(void);
void write_eeprom(uint8_t value);

#endif
