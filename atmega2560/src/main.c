#define __AVR_ATmega2560__
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "../include/spi.h"

void SPI_MasterInit(void) {
   /* Set MOSI and SCK output, all others input */
   DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
   /* Enable SPI, Master, set clock rate fck/16 */ 
   SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}



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