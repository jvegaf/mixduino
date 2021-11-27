

#pragma once
#ifndef MUX_DIGITAL_INPUT_H
#define MUX_DIGITAL_INPUT_H

#include "DigitalInput.h"

class MuxDigitalInput : public DigitalInput
{

public:

	MuxDigitalInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex)
	: DigitalInput(inputIndex)
	{
	    _mxPins = mxPins;
	    _mxSigPin = sig;
	}

	MuxDigitalInput() = default;
	
	void setMuxChannel(uint8_t channel)
	{
	    digitalWrite(_mxPins[0], bitRead(channel, 0));
	    digitalWrite(_mxPins[1], bitRead(channel, 1));
	    digitalWrite(_mxPins[2], bitRead(channel, 2));
	    digitalWrite(_mxPins[3], bitRead(channel, 3));
	}
	
	void read(inputStr_t in) override
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
					in.funOn(in.midiNumber, 127, in.midiChannel);
	            }
	            else
	            {
	                in.funOff(in.midiNumber, 127, in.midiChannel);
	            }

	            _pState = _cState;
	        }
	    }
	}


protected:
	uint8_t _mxSigPin;
	const uint8_t *_mxPins;
};

#endif // MUXINPUT_H
