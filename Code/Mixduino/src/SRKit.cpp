#include "SRKit.h"

SRKit::SRKit(byte clkPin, byte dtPin, byte lchPin)
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

void SRKit::clear(byte nRegs)
{

    byte srs[nRegs] = { };
    for (byte i = 0; i < nRegs; i++)
    {
        srs[i] = 0;
    }

    sendState(srs);
}
void SRKit::sendState(byte *registers)
{
    digitalWrite(latchPin, LOW);
    for (byte i = 0; i < sizeof(registers); i++)
    {
        shiftOut(this->dataPin, this->clockPin, MSBFIRST, registers[i]);
    }
    digitalWrite(latchPin, HIGH);
}
