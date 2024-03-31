#include "masterspi.h"

Master::Master(Address port, const uint8_t &miso, const uint8_t &mosi, const uint8_t &sck, const uint8_t &ss)
    : CSPI()
{
    /* When the SPI is enabled as a master.
    • MISO - Port B, Bit 3: This pin is configured as an input regardless of the setting of DDB3.
    • MOSI – Port B, Bit 2: The data direction of this pin is controlled by DDB2.
    • SCK  – Port B, Bit 1: The data direction of this pin is controlled by DDB1.
    • SS   – Port B, Bit 0: The data direction of this pin is controlled by DDB0.
    */
    control.byte.bit.mstr = true;
    control.wirteRegister();
    *port |= (1 << mosi) | (1 << sck) | (1 << ss);
    *port &= 0b11101111; // aqui acturario miso
}

void Master::setInterfaceUp(const uint8_t &dataOrder, const uint8_t &mode, const uint8_t &clockRate)
{
    control.byte.bit.dord = dataOrder;
    control.byte.bit.mode = mode;
    control.byte.bit.clockRate = clockRate;
    control.wirteRegister();
}

void Master::transferByte(const uint8_t &data)
{
    SPDR = data;
    while (!status.byte.bit.spif)
    {
        status.readRegister();
        asm("nop");
    }
    /* limpiar la bandera
    status.byte.bit.spif = true;
    status.writeRegister();
    */
}
