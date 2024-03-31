#ifndef MAX6675_H
#define MAX6675_H

#include <stdint.h>

/* Notes
    Digitization
        A sequence of all zeros means the thermocouple reading is 0°C.
        A sequence of all ones means the thermocouple reading is +1023.75°C.
    
    D15, is a dummy sign bit and is always zero.
    D14–D3 contain the converted temperature in the order of MSB to LSB
    D2 is normally low and goes high when the thermocouple input is open.
    D1 is low to provide a device ID for the MAX6675
    D0 is three-state.
*/


class Max6675
{
    const float conversionConstant;
    float m_temperature;

    union Sample
    {
        struct Bits
        {
            uint16_t state : 1;
            uint16_t deviceId : 1;
            uint16_t thermocoupleInput : 1;
            uint16_t reading : 12;
            uint16_t signBit : 1;
        };
        Bits bits;
        uint8_t *byte;
    } sample;

public:

    Max6675();

    inline float temperature() const { return m_temperature; }

    void readBuffer(const uint8_t *lsb);
};

#endif