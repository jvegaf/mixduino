
#ifndef ARDUINO_BTNKIT_H
#define ARDUINO_BTNKIT_H
#include <Arduino.h>
#include <MIDI.h>

class BtnKit  
{
	private:

	public:
		void begin();
		void read(void (*func)(uint8_t, uint8_t, uint8_t));

};
#endif
