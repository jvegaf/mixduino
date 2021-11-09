#pragma once
#ifndef FUNCBASE_H
#define FUNCBASE_H
#include "Input.h"
class FuncBase
{
protected:
    Input* _input;
    uint8_t _midiCh;
    uint8_t _note;

public:

    FuncBase(Input *input, uint8_t midiCh, uint8_t note)
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
