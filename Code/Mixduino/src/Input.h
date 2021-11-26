#pragma once
#ifndef MD_INPUT_H
#define MD_INPUT_H
#include "input_str.h"

class Input
{

public:
    Input(uint8_t inputPos)
    {
        _pState = LOW;
        _inPos = inputPos;
    }
    Input() = default;
    virtual void read(inputStr_t in)=0;

protected:
    uint16_t _pState;
    uint16_t _cState;
    uint32_t _lastdebouncetime;
	const uint32_t DEBOUNCE_DELAY = 20;
    uint8_t _inPos;
};


#endif // MDINPUT_H
