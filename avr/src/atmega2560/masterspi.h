#ifndef MASTERSPI_H
#define MASTERSPI_H

#include "spi.h"

/* Port B
• Bit 3 MISO: Master Data input, Slave Data output pin for SPI channel.
When the SPI is enabled as a master, this pin is configured as an input regardless of the setting of DDB3.

• Bit 2 MOSI: SPI Master Data output, Slave Data input for SPI channel.
When the SPI is enabled as a slave, this pin is configured as an input regardless of the setting of DDB2.

• Bit 1 SCK: Master Clock output, Slave Clock input pin for SPI channel.
When the SPI is enabled as a slave, this pin is configured as an input regardless of the setting of DDB1.

• Bit 0 SS: Slave Port Select input.
When the SPI is enabled as a master, the data direction of this pin is controlled by DDB0.
*/

class Master : public CSPI
{
public:
    Master(Address port, const uint8_t &miso, const uint8_t &mosi, const uint8_t &sck, const uint8_t &ss);

    void setInterfaceUp(const uint8_t &dataOrder, const uint8_t &mode, const uint8_t &clockRate);
    void transferByte(const uint8_t &data);
};

#endif