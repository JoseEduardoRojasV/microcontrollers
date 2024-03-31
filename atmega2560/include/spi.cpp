#include "spi.h"
#include <avr/io.h>

SPI::ControlRegister() : spie(false), spe(true), dord(false), 
    mstr(false), cpol(false), cpha(false), spr1(false), spr0(false) {
SREG
}

SPI::SPI() : spcr() {
    
    PRR0 &= 0b1111011; // PRR0 – Power Reduction Register must be written to zero to enable SPI module.
}
SPI::~SPI(){

}

void SPI::sendLSBfirst() {
    spcr.dord = true;
}

void SPI::sendMSBfirst() {
    spcr.dord = false;
}

void SPI::applyChanges() {
    SPCR = spcr;
}

void SPI::startTransmission(const & uint8_t data, uint8_t length) {

}