#include "output.h"

Output::Output(Address DDxn, Address PORTx) : PortX(PORTx)
{
    /* Notes
    The DDxn bit in the DDRx Register selects the direction of this pin.
    If DDxn is written logic one, Pxn is configured as an output pin.
    */

    // Configurar salidas
    *DDxn = 0xFF;
}

Output::~Output()
{
}

void Output::bitSeven(const bool &state)
{
    port.flag.seven = state;
    wirteRegister();
}