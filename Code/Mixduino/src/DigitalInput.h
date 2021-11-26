#pragma once
#ifndef MD_DIGITAL_INPUT_H
#define MD_DIGITAL_INPUT_H
#include "Input.h"

class DigitalInput : public Input
{

public:
    DigitalInput(uint8_t inputPos)
    {
        _pState = LOW;
        _inPos = inputPos;
    }
    DigitalInput() = default;
    virtual void read(inputStr_t in)=0;

protected:
    uint16_t _pState;
    uint16_t _cState;
    uint32_t _lastdebouncetime;
	const uint32_t DEBOUNCE_DELAY = 20;
    uint8_t _inPos;
};


#endif // MDINPUT_H
