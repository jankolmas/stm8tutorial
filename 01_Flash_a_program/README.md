# 01: Flash a program

This tutorial teaches how to flash a minimal working code to the STM8.

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

Now, you can simply build with `make` and flash with `make flash` commands. You should see the onboard LED start blinking.