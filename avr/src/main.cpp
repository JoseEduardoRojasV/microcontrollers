#define F_CPU 16000000UL

#include <util/delay.h>
#include "../src/atmega2560/masterspi.h"

//Master spi(&DDRB,PB3,PB2,PB1,PB0);

int main(void)
{
    //spi.setInterfaceUp(MSB_FIRST, MODE_ZERO, DIVIDE_CLOCK_BY16);

    DDRB |= 1 << PB7;
    while (1)
    {
        _delay_ms(1000);
        PORTB ^= 1 << PINB7;
        _delay_ms(1000);
    }
    return 0;
}
