
#ifndef ARDUINO_BTNKIT_H
#define ARDUINO_BTNKIT_H
#include <Arduino.h>
#include <MIDI.h>
#include <Multiplexer4067.h>
#include "pin_map.h"
#include "sw_muxmap.h"

class BtnKit  
{
	private:
		int parseValue(int value);
	public:
		void begin();
		void read(void (*func)(byte, byte, byte));

};
#endif
