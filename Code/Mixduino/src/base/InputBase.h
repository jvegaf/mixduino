#pragma once
#ifndef MD_INPUTBASE_H
#define MD_INPUTBASE_H
#include <Arduino.h>

class InputBase
{
protected:
    int _pState;
    int _cState;
    unsigned long _lastdebouncetime;
	const unsigned long DEBOUNCE_DELAY = 20;
    uint8_t _inPos;


public:
    InputBase(uint8_t inputIndex)
    {
        _pState = LOW;
        _inPos = inputIndex;
    }
    InputBase() = default;
};


#endif // MDINPUT_H
