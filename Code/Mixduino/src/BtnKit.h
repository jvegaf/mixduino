
#ifndef ARDUINO_BTNKIT_H
#define ARDUINO_BTNKIT_H
#include <Arduino.h>
#include <MIDI.h>

class BtnKit  
{
	private:

	public:
		void begin();
		void read(void (*func)(byte, byte, byte));

};
#endif
