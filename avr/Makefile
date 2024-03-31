
### Flags for compiler
APP      := blink
MICRO    := atmega2560
CFLAGS   := -Os -g -std=gnu++11 -Wall -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -mmcu=$(MICRO) -pedantic
#"-Os" Will avoid optimization warnings re: _delay
COMPILER := avr-g++

LIBS     :=

### Directories struct
SRC        := src
OBJ        := obj
SRC_SUBDIRECTORIES := $(shell find $(SRC)/ -type d)
OBJ_SUBDIRECTORIES := $(patsubst $(SRC)%,$(OBJ)%,$(SRC_SUBDIRECTORIES))

ALL_CPP_FILES := $(shell find src/ -type f -iname *.cpp)
ALL_OBJ_FILES := $(patsubst %.cpp,%.o,$(ALL_CPP_FILES))

.PHONY: directories clean


$(APP).hex : $(APP).elf 
	avr-objcopy $^ -O ihex $@

#To linking
$(APP).elf : $(OBJ_SUBDIRECTORIES) $(ALL_OBJ_FILES)
	$(COMPILER) -mmcu=$(MICRO) $(patsubst $(SRC)%,$(OBJ)%,$(ALL_OBJ_FILES)) $(LIBS) -o $@

$(OBJ_SUBDIRECTORIES) :
	mkdir -p $(OBJ_SUBDIRECTORIES)

#To compiling
%.o : %.cpp
	$(COMPILER) -o $(patsubst $(SRC)%,$(OBJ)%,$@)  -c $^ $(CFLAGS)

 #-Wno-binary-constants

# To load program to board

MCU         := -p $(MICRO)
PROGRAMMER  := -c wiring
PORT        := -P /dev/ttyUSB0
BAUDRATE    := -b 115200
CONFIG_FILE := -C /etc/avrdude.conf
EXECUTABLE  := $(APP).hex

flash: $(EXECUTABLE)
	avrdude  $(MCU) $(PROGRAMMER) $(PORT) $(BAUDRATE) $(CONFIG_FILE) -v -D -U flash:w:$<:i
