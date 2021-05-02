
#ifndef ARDUINO_SRKIT_H
#define ARDUINO_SRKIT_H
#include <Arduino.h>

class SRKit  
{
	private:
		uint8_t clockPin;
		uint8_t dataPin;
		uint8_t latchPin;
	public:
		SRKit(uint8_t clkPin, uint8_t dtPin, uint8_t lchPin);
		void clear(uint8_t nRegs);
		void begin();
		void sendState(uint8_t* registers);

};
#endif



