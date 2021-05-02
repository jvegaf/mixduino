#include "SRKit.h"

SRKit::SRKit(uint8_t clkPin, uint8_t dtPin, uint8_t lchPin)
{
    this->clockPin = clkPin;
    this->dataPin = dtPin;
    this->latchPin = lchPin;
}

void SRKit::begin()
{
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

void SRKit::clear(uint8_t nRegs)
{

    uint8_t srs[nRegs] = { };
    for (uint8_t i = 0; i < nRegs; i++)
    {
        srs[i] = 0;
    }

    sendState(srs);
}
void SRKit::sendState(uint8_t *registers)
{
    digitalWrite(latchPin, LOW);
    for (uint8_t i = 0; i < sizeof(registers); i++)
    {
        shiftOut(this->dataPin, this->clockPin, MSBFIRST, registers[i]);
    }
    digitalWrite(latchPin, HIGH);
}
