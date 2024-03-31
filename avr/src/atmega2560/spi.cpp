#include "spi.h"

CSPI::CSPI() : status(), control() 
{
    // asm volatile("" : : : "memory");
    //  PRR0 – Power Reduction Register must be written to zero to enable SPI module.
    control.readRegister();
    control.byte.bit.spe = true;
    control.wirteRegister();
}

CSPI::~CSPI()
{

}