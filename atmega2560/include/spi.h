#include <stdint.h>

//Registro por verificar SPCR (SPI Status Register)
//Registro por verificar SPDR (SPI Data Register)

class SPI {
protected:
    
    struct ControlRegister { // SPI Control Register

    uint8_t SPIE : 1; // SPI Interrupt Enable
    uint8_t SPE  : 1; // SPI Enable
    uint8_t DORD : 1; // Data Order
    uint8_t MSTR : 1; // Master/Slave Select
    uint8_t CPOL : 1; // Clock Polarity
    uint8_t CPHA : 1; // Clock Phase
    uint8_t SPR1 : 1; // SPI Clock Rate Select 1 and 0
    uint8_t SPR0 : 1; // SPI Clock Rate Select 1 and 0
    
    ControlRegister() : SPIE(false), SPE(true), DORD(false), 
    MSTR(false), CPOL(false), CPHA(false), SPR1(false), SPR0(false) { }
    } spcr;

public:

    SPI() : spcr() {}

    void enableInterrupt() { spcr.SPIE = true   }
    void sendLSBfirst()    { spcr.DORD = true;  }
    void sendMSBfirst()    { spcr.DORD = false; }

    ~SPI(){ }
};

class Master : public SPI {

    Master() : SPI() {
        SPCR.MSTR = true;
    }

    void enableMode1() { spcr.CPOL = false; spcr.CPHA = false; }
    void enableMode2() { spcr.CPOL = false; spcr.CPHA = true;  }
    void enableMode3() { spcr.CPOL = true;  spcr.CPHA = false; }
    void enableMode4() { spcr.CPOL = true;  spcr.CPHA = true;  }

};

class Slave : public SPI {

    Slave() : SPI() {
    spcr.MSTR = false;
    }
};

struct StatusRegister // SPI Status Register
{
    uint8_t SPIF     : 1; // SPI Interrupt Flag
    uint8_t WCOL     : 1; // Write COLlision Flag
    uint8_t Reserved : 5; // These bits are reserved bits and will always read as zero.
    uint8_t SPI2X    : 1; // Double SPI Speed Bit
};
