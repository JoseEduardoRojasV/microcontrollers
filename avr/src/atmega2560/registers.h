#ifndef REGISTERS_H
#define REGISTERS_H
// #define __AVR_ATmega2560__
#include <avr/io.h>

// La versión del compilador no admite el uso de using
// using Address = volatile uint8_t *const;
typedef volatile uint8_t *Address;

class PortX
{
protected:
    union Port
    {
        struct Bits
        {
            uint8_t zero : 1;
            uint8_t one : 1;
            uint8_t two : 1;
            uint8_t three : 1;
            uint8_t four : 1;
            uint8_t five : 1;
            uint8_t six : 1;
            uint8_t seven : 1;
        };

        Bits flag;
        uint8_t allBits;
    } port;

    explicit PortX(Address add);

public:
    void readRegister();
    void wirteRegister();

private:
    Address address;
};

union PowerReduction0 // Power Reduction Register 0
{
    uint8_t data;
    struct Bits
    {
        uint8_t prtWI : 1;
        uint8_t prtIM2 : 1;
        uint8_t prtIM0 : 1;
        uint8_t prtIM1 : 1;
        uint8_t Reserved : 1;
        uint8_t prSPI : 1;
        uint8_t prUSART0 : 1;
        uint8_t prADC : 1;
    } bit;
    PowerReduction0() : data(0) { data = PRR0; }
};

namespace SPI
{
    // There are four combinations of SCK phase and polarity with respect to serial data.
    constexpr uint8_t MODE_ZERO{0};  // CPOL=0, CPHA=0
    constexpr uint8_t MODE_ONE{1};   // CPOL=0, CPHA=1
    constexpr uint8_t MODE_TWO{2};   // CPOL=1, CPHA=0
    constexpr uint8_t MODE_THREE{3}; // CPOL=1, CPHA=1
    // SPI Clock Rate
    constexpr uint8_t DIVIDE_CLOCK_BY4{0};
    constexpr uint8_t DIVIDE_CLOCK_BY16{1};
    constexpr uint8_t DIVIDE_CLOCK_BY64{2};
    constexpr uint8_t DIVIDE_CLOCK_BY128{3};

    struct ControlRegister : public PortX
    {
        void enableInterrupt(const bool &state) { port.flag.one = state; } // uint8_t spie : 1;
        void enableSPI(const bool &state) { port.flag.one = state; }       // uint8_t spe : 1;
        void setDataOrderUp(const uint8_t &mode) { port.allBits = mode; }  // Data Order
        void enableMaster(const bool &state) { port.flag.four = state; }   // uint8_t mstr : 1;
        void setModeUp(const uint8_t &mode) { port.allBits = mode; }       // uint8_t mode : 2;                                               // Clock Polarity and Clock Phase
        void setClockRateUp(const uint8_t &mode) { port.allBits = mode; }  // uint8_t clockRate : 2;

        ControlRegister();
    };

    struct StatusRegister : public PortX
    {

        bool spif() const { return port.flag.one; }
        bool wcol() const { return port.flag.two; }
        bool spi2x() const { return port.flag.seven; }

        void cleanSpifFlag() { port.flag.one = 1; }
        void cleanWcolFlag() { port.flag.two = 1; }
        void cleanSpi2xFlag() { port.flag.seven = 1; }

        //  uint8_t spif : 1;     // SPI Interrupt Flag
        //  uint8_t wcol : 1;     // Write COLlision Flag
        //  uint8_t Reserved : 5; // These bits are reserved bits and will always read as zero.
        //  uint8_t spi2x : 1;    // Double SPI Speed Bit
        StatusRegister();
    };

}

#endif