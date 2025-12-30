# 03: EEPROM read and write

This tutorial teaches how to read and write values to EEPROM that persist a reboot and programming

The program will write a value determined in the code. If the value was previously missing or
different, the program will write it and the LED will light up for 1s to indicate writing.

If the value was the same, the program will blink twice quickly to indicate that the value
is already stored.

## Build and flash

Build with `make` and flash with `make flash` commands.