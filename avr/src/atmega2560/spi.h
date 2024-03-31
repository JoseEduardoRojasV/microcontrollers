#ifndef CSPI_H
#define CSPI_H

#include "registers.h"

/*
• MISO/PCINT3 – Port B, Bit 3 MISO: Master Data input, Slave Data output pin for SPI channel.
When the SPI is enabled as a master, this pin is configured as an input regardless of the setting of DDB3.
When the SPI is enabled as a slave, the data direction of this pin is controlled by DDB3.

• MOSI/PCINT2 – Port B, Bit 2 MOSI: SPI Master Data output, Slave Data input for SPI channel.
When the SPI is enabled as a slave, this pin is configured as an input regardless of the setting of DDB2.
When the SPI is enabled as a master, the data direction of this pin is controlled by DDB2.

• SCK/PCINT1 – Port B, Bit 1 SCK: Master Clock output, Slave Clock input pin for SPI channel.
When the SPI is enabled as a slave, this pin is configured as an input regardless of the setting of DDB1.
When the SPI is enabled as a master, the data direction of this pin is controlled by DDB1.

•SS/PCINT0 – Port B, Bit 0 SS: Slave Port Select input. When the SPI is enabled as a slave, this pin is
configured as an input regardless of the setting of DDB0. As a slave, the SPI is activated when this pin is
driven low. When the SPI is enabled as a master, the data direction of this pin is controlled by DDB0.
*/

const uint8_t MSB_FIRST{1};
const uint8_t LSB_FIRST{0};

class CSPI
{
protected:
    CSPI();

    SPI::StatusRegister  status;
    SPI::ControlRegister control;

    // Data Order
    const bool LSB_FIRST{1}; // the LSB of the data word is transmitted first.
    const bool MSB_FIRST{0}; // the MSB of the data word is transmitted first.

public:
    ~CSPI();
    // void transfer(const & uint8_t data, uint8_t length) {};
};

#endif