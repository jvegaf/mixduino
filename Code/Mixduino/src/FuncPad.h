#pragma once
#ifndef FUNCPAD_H
#define FUNCPAD_H
#include <Arduino.h>
#include "Func.h"

class FuncPad : Func
{
	private:

	public:
		FuncPad(Input* input, Output* output, uint8_t midiCh, uint8_t note);
		FuncPad() = default;
		void setNote(uint8_t note);
		void read();
		void setTo(uint8_t value);

};
#endif
