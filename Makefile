MCU = stm8s103
TARGET = main

CC = sdcc
CFLAGS = -mstm8 --opt-code-size

SRC = src/main.c
INC = -Iinc

all:
	$(CC) $(CFLAGS) $(INC) $(SRC) -o build/$(TARGET).ihx

flash: all
	stm8flash -c stlinkv2 -p stm8s103f3 -w build/$(TARGET).ihx

clean:
	rm -f *.ihx *.lk *.map *.lst *.rel *.rst *.sym *.asm
