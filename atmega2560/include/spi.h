#include <stdint.h>

//Registro por verificar SPCR (SPI Status Register)
//Registro por verificar SPDR (SPI Data Register)

class SPI {
protected:
    
    struct ControlRegister { // SPI Control Register

    uint8_t spie : 1; // SPI Interrupt Enable
    uint8_t spe  : 1; // SPI Enable
    uint8_t dord : 1; // Data Order
    uint8_t mstr : 1; // Master/Slave Select
    uint8_t cpol : 1; // Clock Polarity
    uint8_t cpha : 1; // Clock Phase
    uint8_t spr1 : 1; // SPI Clock Rate Select 1 and 0
    uint8_t spr0 : 1; // SPI Clock Rate Select 1 and 0
    
    ControlRegister()
    } spcr;

public:
    
    SPI()
    ~SPI()

    inline isLSBfirstEnabled() const { return spcr.dord;  }
    inline isMSBfirstEnabled() const { return !spcr.dord; }

    void sendLSBfirst()
    void sendMSBfirst()
    void applyChanges()

    void startTransmission(const & uint8_t data, uint8_t length)


};

struct StatusRegister // SPI Status Register
{
    uint8_t SPIF     : 1; // SPI Interrupt Flag
    uint8_t WCOL     : 1; // Write COLlision Flag
    uint8_t Reserved : 5; // These bits are reserved bits and will always read as zero.
    uint8_t SPI2X    : 1; // Double SPI Speed Bit
};
