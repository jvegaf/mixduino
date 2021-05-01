#include "SRKit.h"


SRKit::SRKit(uint8_t* regs, uint8_t clkPin, uint8_t dtPin, uint8_t lchPin)
{
    this->clockPin = clkPin;
    this->dataPin = dtPin;
    this->latchPin = lchPin;
    this->regs = regs;
    this->values = {0};
}

void SRKit::begin()
{
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    this->clear();
}

void SRKit::changeState(uint8_t reg, uint8_t value) {
	for ( uint8_t i=0; i< sizeof(this->regs); i++) 
    {
        if (regs[i] != reg) continue;
        
        if(values[i] == value) break;
        
        values[i] = value;
        
        sendState(this->values);
    }
}



void SRKit::clear() {
    
	uint8_t srs[sizeof(this->regs)] = {0};

    sendState(srs);
}
void SRKit::sendState(uint8_t* regValues) {
	digitalWrite(latchPin, LOW);
    for (uint8_t i = 0; i < sizeof(regValues); i++)
    {
        shiftOut(this->dataPin, this->clockPin, MSBFIRST, regValues[i]);
    }
    digitalWrite(latchPin, HIGH);
}
