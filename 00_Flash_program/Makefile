MCU = stm8s103 # This is our microprocessor
TARGET = main# The name of our resulting binary
CC = sdcc # We use sdcc to compile our C code
CFLAGS = -mstm8 --opt-code-size # Target STM8 architecrure and minimize size
SRC = src/main.c # For now there is just one source file


# Compiles the code into intel hex format. Since it is the first command,
# running `make` is equivalent to `make all`
all: clean
	$(CC) $(CFLAGS) $(SRC) -o build/$(TARGET).ihx

# Remove the build folder
clean:
	rm -rf build
	mkdir -p build

# Flash the compiled code onto the microprocessor
flash: all
	stm8flash -c stlinkv2 -p $(MCU) -w build/$(TARGET).ihx
