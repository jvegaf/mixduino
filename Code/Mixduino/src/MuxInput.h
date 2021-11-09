

#pragma once
#ifndef MUXINPUT_H
#define MUXINPUT_H

#include "Input.h"
#include <Arduino.h>

class MuxInput : public Input
{

public:

	MuxInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
	: Input(inputIndex, funcOn, funcOff)
	{
	    _mxPins = mxPins;
	    _mxSigPin = sig;
	}

	MuxInput() = default;
	
	void setMuxChannel(uint8_t channel)
	{
	    digitalWrite(_mxPins[0], bitRead(channel, 0));
	    digitalWrite(_mxPins[1], bitRead(channel, 1));
	    digitalWrite(_mxPins[2], bitRead(channel, 2));
	    digitalWrite(_mxPins[3], bitRead(channel, 3));
	}
	
	void read(uint8_t midiCh, uint8_t note)
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
	                _funOn(note, 127, midiCh);
	            }
	            else
	            {
	                _funOff(note, 127, midiCh);
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
