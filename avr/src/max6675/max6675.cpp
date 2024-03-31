#include "max6675.h"

Max6675::Max6675() : conversionConstant(10.25), m_temperature(0)
{

}

void Max6675::readBuffer(const uint8_t *lsb)
{
    *sample.byte = *lsb;
    *(sample.byte + 1) = *(lsb + 1);
    m_temperature = conversionConstant * static_cast<float>(sample.bits.reading);
}
