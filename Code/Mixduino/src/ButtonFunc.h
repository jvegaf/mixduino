#pragma once
#ifndef MD_BUTTONFUNC_H
#define MD_BUTTONFUNC_H
#include "Button.h"

class ButtonFunc : public Button
{

public:

    ButtonFunc(
        Input* input, 
        Output* output, 
        void (*funcOn)(uint8_t, uint8_t, uint8_t))
    : Button(input, output)
    {
        _fnOn = funcOn;
    }

    void read() override
    {
        inputStr_t inStr;
        inStr.funOn = _fnOn;
        _input->read(inStr);
    }

protected:
    void (*_fnOn)(uint8_t, uint8_t, uint8_t);
};

#endif