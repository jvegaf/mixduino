
#ifndef ARDUINPUT_H
#define ARDUINPUT_H
#include <Arduino.h>
#include "Input.h"

class ArduInput : public Input  
{
	public:
		ArduInput(uint8_t inputIndex)
		: Input(inputIndex)
		{
		}

		void read(inputStr_t in) override
		{
		    _cState = digitalRead(_inPos);
		    if ((millis() - _lastdebouncetime) > DEBOUNCE_DELAY)
		    {

		        if (_cState != _pState)
		        {
		            _lastdebouncetime = millis();

		            if (_cState == LOW)
		            {
						in.funOn(in.midiNote, 127, in.midiChannel); // envia NoteOn(nota, velocity, canal midi)
		            }
		            else
		            {
		                in.funOff(in.midiNote, 127, in.midiChannel); // envia NoteOff(nota, velocity, canal midi)
		            }

		            _pState = _cState;
		        }
		    }
		}

};
#endif
