#ifndef REGISTERS_H
#define REGISTERS_H
//#define __AVR_ATmega2560__
#include <avr/io.h>

//La versión del compilador no admite el uso de using 
//using Address = volatile uint8_t *const;
typedef volatile uint8_t *const Address;

struct Register
{
    void readRegister();
    void wirteRegister();

protected:
    explicit Register(Address add);
    uint8_t value;

private:
    Address address;
};

union PowerReduction0 // Power Reduction Register 0
{
    uint8_t data;
    struct
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
    struct ControlRegister : public Register
    {
        ControlRegister();

        union DataRegister
        {
            uint8_t *data;
            struct
            {
                uint8_t spie : 1;      // SPI Interrupt Enable
                uint8_t spe : 1;       // SPI Enable
                uint8_t dord : 1;      // Data Order
                uint8_t mstr : 1;      // Master/Slave Select
                uint8_t mode : 2;      // Clock Polarity and Clock Phase
                uint8_t clockRate : 2; // SPI Clock Rate Select 1 and 0
            } bit;
        } byte;
    };

    struct StatusRegister : public Register
    {
        StatusRegister();
        union DataRegister // SPI Status Register
        {
            uint8_t *data;
            struct
            {
                uint8_t spif     : 1; // SPI Interrupt Flag
                uint8_t wcol     : 1; // Write COLlision Flag
                uint8_t Reserved : 5; // These bits are reserved bits and will always read as zero.
                uint8_t spi2x    : 1; // Double SPI Speed Bit
            } bit;
        } byte;
    };

}

#endif