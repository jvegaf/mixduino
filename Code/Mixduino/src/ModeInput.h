#pragma once
#ifndef MODEINPUT_H
#define MODEINPUT_H
#include <Arduino.h>
#include "MuxInput.h"

class ModeInput : public MuxInput
{
	public:
		ModeInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex)
		:MuxInput(mxPins, sig, inputIndex)
		{
		}


		void read(void (*incFn)())
		{
		    setMuxChannel(_inPos);
		    _cState = digitalRead(_mxSigPin);
		    if ((millis() - _lastdebouncetime) > DEBOUNCE_DELAY)
		    {
		        if (_pState != _cState)
		        {
		            _lastdebouncetime = millis();

		            if (_cState == LOW)
		            {
		                incFn();
		            }
		            _pState = _cState;
		        }
		    }
		}


};
#endif
