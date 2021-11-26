#pragma once
#ifndef FUNCBASE_H
#define FUNCBASE_H
#include "DigitalInput.h"
class FuncBase
{
protected:
    DigitalInput* _input;
    uint8_t _midiCh;
    uint8_t _note;

public:

    FuncBase(DigitalInput *input, uint8_t midiCh, uint8_t note)
    {
        _input = input;
        _midiCh = midiCh;
        _note = note;
    }

    FuncBase() = default;

    void read()
    {
        _input->read(_midiCh, _note);
    }
};

#endif // FUNCBASE_H
