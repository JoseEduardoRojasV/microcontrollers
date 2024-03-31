#ifndef SLAVESPI_H
#define SLAVESPI_H

#include "spi.h"

class Slave : public CSPI
{
public:
    Slave();

    uint8_t receiveByte();
};

#endif