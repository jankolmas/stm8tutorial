MCU = stm8s103
TARGET = main

CC = sdcc
CFLAGS = -mstm8 --opt-code-size

SRC = src/main.c
INC = -Iinc

all: clean
	$(CC) $(CFLAGS) $(INC) $(SRC) -o build/$(TARGET).ihx

clean:
	rm -rf build
	mkdir -p build

flash: all
	stm8flash -c stlinkv2 -p stm8s103f3 -w build/$(TARGET).ihx
