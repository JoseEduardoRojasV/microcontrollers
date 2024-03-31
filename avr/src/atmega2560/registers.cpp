#include "registers.h"

Register::Register(Address add) : value(0), address(add)
{
    
}

void Register::readRegister()
{
    value = *address;
}

void Register::wirteRegister()
{
    *address = value;
}

namespace SPI
{
    ControlRegister::ControlRegister() : Register(&SPCR)
    {
        byte.data = &value;
    }
    StatusRegister::StatusRegister() : Register(&SPSR)
    {
        byte.data = &value;
    }

} // namespace SPI
