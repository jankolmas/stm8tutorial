# 00: Flash a program

This chapter teaches how to flash a program to the STM8. 

## Set up hardware

You will need:

* STM8S103F3P6 development board
* Male headers
* ST-Link v2
* 4-pin female to female jumper

If you haven't done so yet, solder the headers to the STM8 board. There are two rows of 10, plus one row of 4.

Connect the ST-Link v2 to the STM8 board 4-pin connector using female to female jumper cables. Pay attention to correctly match the RST, GND, SWIM and 3.3V pins.


## Setup environment

These are instructions for a Ubuntu-like OS. It is possible to build and flash STM8 from Windows as well using STVD and STVP, but it is way more straightforward on Linux. It is possible to do everything from terminal and text editor, but I find it helpful to use an IDE such as VS Code.

Install build tools:

```
sudo apt update
sudo apt install sdcc make
```

Install flashing tools from source:

```
sudo apt install git build-essential libusb-1.0-0-dev pkg-config
cd ~
git clone https://github.com/vdudouyt/stm8flash.git
cd stm8flash
make
sudo cp stm8flash /usr/local/bin/
```

## Build and flash

Now, you can simply build with `make` and flash with `make flash` commands. 

The program is currently not doing anything, we are just testing that we can upload a program to the STM8.