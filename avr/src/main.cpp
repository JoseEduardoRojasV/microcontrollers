#define F_CPU 16000000UL

#include <util/delay.h>

#include "../src/atmega2560/masterspi.h"
#include "../src/atmega2560/output.h"
#include "../src/max6675/max6675.h"

// Master spi(&DDRB,PB3,PB2,PB1,PB0);
Max6675 max6675;

int main(void)
{
    // spi.setInterfaceUp(MSB_FIRST, SPI::MODE_ZERO, SPI::DIVIDE_CLOCK_BY16);

    uint8_t buffer;
    max6675.readBuffer(&buffer);

    Output portb(&DDRB, &PORTB);
    
    while (1)
    {
        portb.bitSeven(true);
        _delay_ms(1000);
        portb.bitSeven(false);
        _delay_ms(1000);
    }
    return 0;
}