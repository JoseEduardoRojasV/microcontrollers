#include "spi.h"

class Slave : public SPI {

    Slave() : SPI() {
    spcr.mstr = false;
    }
};