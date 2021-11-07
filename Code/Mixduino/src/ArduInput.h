
#ifndef ARDUINPUT_H
#define ARDUINPUT_H
#include <Arduino.h>
#include "Input.h"

class ArduInput : public Input  
{
	public:
		ArduInput(uint8_t inputIndex, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
		void read(uint8_t midiCh, uint8_t note);

};
#endif
