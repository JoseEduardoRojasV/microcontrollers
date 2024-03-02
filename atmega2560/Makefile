PROGRAM_NAME := blink

#Referencias
# https://www.nongnu.org/avrdude/user-manual/avrdude_1.html#Introduction

# To compile a board


# To load program to board

CPU        := atmega2560
PORT       := /dev/ttyUSB0
BAUD_RATE  := 115200
EXECUTABLE := $(PROGRAM_NAME).hex

flash: $(EXECUTABLE)
	avrdude -C /etc/avrdude.conf -v -p $(CPU) -c wiring -P $(PORT) -b $(BAUD_RATE) -D -U flash:w:$<:i

#.PHONY : clean
#clean