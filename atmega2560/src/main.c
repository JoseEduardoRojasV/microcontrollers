#define __AVR_ATmega2560__
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{ 
    DDRB |=  1 << PB7;
    while(1)
    {
        _delay_ms(1000);
        PORTB ^= 1 << PINB7;
        _delay_ms(1000);
    }
    return 0;
}