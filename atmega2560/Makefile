PROGRAM_NAME := blink

#Referencias
# https://www.nongnu.org/avrdude/user-manual/avrdude_1.html#Introduction

# To compile a board


# To load program to board

MCU         := -p atmega2560
PROGRAMMER  := -c wiring
PORT        := -p /dev/ttyUSB0
BAUDRATE    := -b 115200
CONFIG_FILE := -C /etc/avrdude.conf
EXECUTABLE  := $(PROGRAM_NAME).hex

flash: $(EXECUTABLE)
	avrdude  $(MCU) $(PROGRAMMER) $(PORT) $(BAUDRATE) $(CONFIG_FILE) -v -D -U flash:w:$<:i

#.PHONY : clean
#clean