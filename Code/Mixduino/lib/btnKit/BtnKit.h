
#ifndef ARDUINO_BTNKIT_H
#define ARDUINO_BTNKIT_H
#include <Arduino.h>
#include <MIDI.h>
#include <Multiplexer4067.h>
#include <MDState.h>
#include "md_pinmap.h"
#include "sw_muxmap.h"

class BtnKit
{
private:
	uint8_t *pins;
	uint8_t totalPins;
	int *pState;
	int *cState;

	unsigned long* lastdebouncetime;
	unsigned long debouncedelay = 20;
public:
	BtnKit(const uint8_t* arduinoPins, const uint8_t tPins); 
	void begin();
	MDState read(uint8_t input_pos);
};
#endif
