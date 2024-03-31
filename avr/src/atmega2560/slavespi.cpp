#include "slavespi.h"

Slave::Slave() : CSPI()
{
    control.byte.bit.mstr = false;
}

uint8_t Slave::receiveByte()
{
    status.byte.data = 0;
    while (!status.byte.bit.spif)
    {
        status.readRegister();
        asm("nop");
    }
    return SPDR;
}
