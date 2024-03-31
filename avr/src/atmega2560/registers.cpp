#include "registers.h"

PortX::PortX(Address add) : address(add)
{

}

void PortX::readRegister()
{
    port.allBits = *address;
}

void PortX::wirteRegister()
{
    *address = port.allBits;
}

















Register::Register(Address add) : value(0), ptrBits(0), address(add)
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

Port::Port(Address add) : Register(add)
{
    //port.data = &value;
    Register::ptrBits = &port.data;
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
