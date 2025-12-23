# STM8 tutorial

This is a minimal working code for STM8. I will add more working examples later.

## Setup environment

These are instructions for a Ubuntu-like OS. It is possible to build and flash STM8 from Windows as well using STVD and STVP, but it is way more modern and straightforward on Linux.

Install build tools:

```
sudo apt update
sudo apt install sdcc make cmake git
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