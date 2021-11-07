#pragma once
#ifndef MD_PAD_H
#define MD_PAD_H
#include <Arduino.h>
#include "FuncPad.h"

class Pad  
{
	private:
		FuncPad* _funcPads;
	public:
		Pad(FuncPad* funcpads);
		void setNote(uint8_t note);
		void read();
		void setTo(uint8_t value);
		void setTo(uint8_t position, uint8_t value);
};
#endif
