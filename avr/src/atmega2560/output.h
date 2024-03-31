#ifndef OUTPUTS_H
#define OUTPUTS_H

#include "registers.h"

class Output : public PortX
{
public:
    Output(Address DDxn, Address PORTx);
    ~Output();

    void bitSeven(const bool &state);


};

#endif