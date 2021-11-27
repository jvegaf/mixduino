#pragma once
#ifndef MD_BUTTONFUNC_H
#define MD_BUTTONFUNC_H
#include "Button.h"

class ButtonFunc : public Button
{

public:

    ButtonFunc(
        DigitalInput* input, 
        Output* output, 
        void (*cbackFun)())
    : Button(input, output), _cbackFun{cbackFun}
    {
    }

    ButtonFunc(
        DigitalInput* input, 
        Output* output, 
        void (*cbackFun)(uint8_t))
    : Button(input, output), _cbackMode{cbackFun}
    {
    }

    void read() override
    {
        inputStr_t inStr;
        if(_cbackFun != nullptr)
        {
            inStr.cbackFun = _cbackFun;
        }
        if(_cbackMode != nullptr)
        {
            inStr.cbackMode = _cbackMode;
        }
        
        _input->read(inStr);
    }

protected:
    void (*_cbackFun)() { nullptr };
    void (*_cbackMode)(uint8_t) { nullptr };
};

#endif