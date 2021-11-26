#pragma once
#ifndef MD_FUNC_H
#define MD_FUNC_H
#include <Arduino.h>
#include "FuncBase.h"
#include "Output.h"

class Func : public FuncBase
{
	protected:
		Output* _output;

	public:
		Func(Output* output);
		Func(DigitalInput* input, Output* output);
		Func(DigitalInput* input, Output* output, uint8_t midiCh, uint8_t note);
		Func() = default;
		void read();
		void setTo(uint8_t value);


};
#endif
