#pragma once
#ifndef MD_FUNC_H
#define MD_FUNC_H
#include <Arduino.h>
#include "FuncBase.h"
#include "OutputBase.h"

class Func : public FuncBase
{
	protected:
		OutputBase* _output;

	public:
		Func(Input* input, OutputBase* output);
		Func(Input* input, OutputBase* output, uint8_t midiCh, uint8_t note);
		Func() = default;
		void read();
		void setTo(uint8_t value);


};
#endif
