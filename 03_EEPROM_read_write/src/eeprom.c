#include "eeprom.h"

void eeprom_write_byte(uint8_t address, uint8_t data)
{
    // Wait until the EEPROM is ready for a new write operation
    while (EEPROM_SR & 0x01);  // Check the EOP (End of Programming) flag

    // Set the address and data registers
    EEPROM_FPR = address;
    EEPROM_FDR = data;

    // Start the write operation
    EEPROM_CR |= 0x02;  // Set the PRG bit to start programming

    // Wait until the write operation is complete
    while (EEPROM_SR & 0x01);  // Check the EOP flag again
}

uint8_t eeprom_read_byte(uint8_t address)
{
    // Set the address register
    EEPROM_FPR = address;

    // Start the read operation
    EEPROM_CR |= 0x01;  // Set the RD bit to start reading

    // Wait until the read operation is complete
    while (EEPROM_SR & 0x01);  // Check the EOP flag

    // Return the data from the data register
    return EEPROM_FDR;
}