# 03: EEPROM read and write

This tutorial teaches how to read and write values to EEPROM that persist a reboot and programming

## Build and flash

Build with `make` and flash with `make flash` commands. See instructions in chapter 00 on how to set up the hardware and development environment.

You can set a value of a byte in EEPROM memory to any value 0-255, for example to 5 with `make eeprom 5`. The program will then read the value and blink that many times. You can also read the value with the programmer with `make eeprom-read`
