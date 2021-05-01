
#ifndef ARDUINO_SRKIT_H
#define ARDUINO_SRKIT_H
#include <Arduino.h>
#include "pin_map.h"

class SRKit  
{
	private:
		uint8_t clockPin;
		uint8_t dataPin;
		uint8_t latchPin;
		uint8_t* regs;
		uint8_t* values;
		void clear();
		void sendState(uint8_t* registers);
	public:
		SRKit(uint8_t* regs, uint8_t clkPin, uint8_t dtPin, uint8_t lchPin);
		void begin();
		void changeState(uint8_t reg, uint8_t value);

};
#endif



