#include "SRKit.h"

SRKit::SRKit(byte clkPin, byte dtPin, byte lchPin, byte nRegs)
{
    clockPin = clkPin;
    dataPin = dtPin;
    latchPin = lchPin;
    regsAmount = nRegs;
} 

void SRKit::begin()
{
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    digitalWrite(clockPin, LOW);
    digitalWrite(latchPin, LOW);
    clear();
}

void SRKit::clear()
{
    byte regs[regsAmount] = {};
    for (byte i = 0; i < regsAmount; i++)
    {
        regs[i] = B00000000;
        sendState(regs);
    }
}
void SRKit::sendState(byte* regs)
{
    digitalWrite(latchPin, LOW);
    for (byte i = 0; i < regsAmount; i++)
    {
        shiftOut(this->dataPin, this->clockPin, MSBFIRST, regs[i]);
    }
    digitalWrite(latchPin, HIGH);
}
