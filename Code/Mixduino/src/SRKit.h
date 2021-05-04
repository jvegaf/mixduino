
#ifndef ARDUINO_SRKIT_H
#define ARDUINO_SRKIT_H
#include <Arduino.h>

class SRKit  
{
	private:
		byte clockPin;
		byte dataPin;
		byte latchPin;
	public:
		SRKit(byte clkPin, byte dtPin, byte lchPin);
		void clear(byte nRegs);
		void begin();
		void sendState(byte* registers);

};
#endif



