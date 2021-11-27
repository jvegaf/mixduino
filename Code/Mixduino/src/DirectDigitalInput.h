
#ifndef ARDUINPUT_H
#define ARDUINPUT_H
#include <Arduino.h>
#include "DigitalInput.h"

class DirectDigitalInput : public DigitalInput  
{
	public:
		DirectDigitalInput(uint8_t inputIndex)
		: DigitalInput(inputIndex)
		{
		}

		DirectDigitalInput() = default;

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
						in.funOn(in.midiNumber, 127, in.midiChannel); // envia NoteOn(nota, velocity, canal midi)
		            }
		            else
		            {
		                in.funOff(in.midiNumber, 127, in.midiChannel); // envia NoteOff(nota, velocity, canal midi)
		            }

		            _pState = _cState;
		        }
		    }
		}

};
#endif
