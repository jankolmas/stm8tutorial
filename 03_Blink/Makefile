MCU = stm8s103
TARGET = main

CC = sdcc
CFLAGS = -mstm8 --opt-code-size

SRC = $(wildcard src/*.c)
INC = -Iinc

OBJS = $(addprefix build/,$(notdir $(SRC:.c=.rel)))

all: clean $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o build/$(TARGET).ihx

build/%.rel: src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf build
	mkdir -p build

flash: all
	stm8flash -c stlinkv2 -p stm8s103f3 -w build/$(TARGET).ihx
