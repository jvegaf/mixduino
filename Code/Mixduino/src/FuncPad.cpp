#include "FuncPad.h"  

FuncPad::FuncPad(DigitalInput* input, Output* output, uint8_t midiCh, uint8_t note)
	: Func(input, output, midiCh, note)
{
	
}

void FuncPad::setNote(uint8_t note) {
	_note = note;
}

void FuncPad::read() {
	Func::read();
}

void FuncPad::setTo(uint8_t value) {
	Func::setTo(value);
}

