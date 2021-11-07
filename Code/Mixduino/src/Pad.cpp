#include "Pad.h"  

Pad::Pad(FuncPad* funcpads)
{
	_funcPads = funcpads;
}

void Pad::setNote(uint8_t note) {
	for (uint8_t i = 0; i < 8; i++)
    {
        _funcPads[i].setNote(note);
    }
}

void Pad::read() {
	for (uint8_t i = 0; i < 8; i++)
    {
        _funcPads[i].read();
    }
    
}

void Pad::setTo(uint8_t value) {
	for (uint8_t i = 0; i < 8; i++)
    {
        _funcPads[i].setTo(value);
    }
}

void Pad::setTo(uint8_t position, uint8_t value) {
	_funcPads[position].setTo(value);
}
