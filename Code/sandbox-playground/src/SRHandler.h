
#ifndef ARDUINO_SRHANDLER_H
#define ARDUINO_SRHANDLER_H
#include <Arduino.h>

class SRHandler  
{
	private:
		unsigned int ccVuLLastValue;
		unsigned int ccVuRLastValue;
		void setRegister(int val, unsigned int pinSet[]);
	public:
		SRHandler();
		void begin();
		void valueDidChange(byte number, byte value);

};
#endif
