#include "spi.h"

class Master : public SPI {

    Master() : SPI() {
        spcr.mstr = true;
    }

    void enableMode1() { spcr.cpol = false; spcr.cpha = false; }
    void enableMode2() { spcr.cpol = false; spcr.cpha = true;  }
    void enableMode3() { spcr.cpol = true;  spcr.cpha = false; }
    void enableMode4() { spcr.cpol = true;  spcr.cpha = true;  }

};