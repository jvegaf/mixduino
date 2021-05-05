
#ifndef ARDUINO_SRKIT_H
#define ARDUINO_SRKIT_H
#include <Arduino.h>

class SRKit  
{
	private:
		byte clockPin;
		byte dataPin;
		byte latchPin;
		byte regsAmount;
	public:
		SRKit(byte clkPin, byte dtPin, byte lchPin, byte nRegs);
		void clear();
		void begin();
		void sendState(byte* regs);

};
#endif



