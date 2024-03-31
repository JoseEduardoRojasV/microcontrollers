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

// There are four combinations of SCK phase and polarity with respect to serial data.
const uint8_t MODE_ZERO{0};  // CPOL=0, CPHA=0
const uint8_t MODE_ONE{1};   // CPOL=0, CPHA=1
const uint8_t MODE_TWO{2};   // CPOL=1, CPHA=0
const uint8_t MODE_THREE{3}; // CPOL=1, CPHA=1
// SPI Clock Rate
const uint8_t DIVIDE_CLOCK_BY4{0};
const uint8_t DIVIDE_CLOCK_BY16{1};
const uint8_t DIVIDE_CLOCK_BY64{2};
const uint8_t DIVIDE_CLOCK_BY128{3};

class Master : public CSPI
{
public:
    Master(Address port, const uint8_t &miso, const uint8_t &mosi, const uint8_t &sck, const uint8_t &ss);

    void setInterfaceUp(const uint8_t &dataOrder, const uint8_t &mode, const uint8_t &clockRate);
    void transferByte(const uint8_t &data);
};

#endif