#pragma once
#ifndef MD_POT_H
#define MD_POT_H
#include "AnalogInput.h"

class Pot
{

public:
    Pot(
        AnalogInput *analogInput,
        uint8_t midiChannel,
        uint8_t midiNumber,
        void (*funCC)(uint8_t, uint8_t, uint8_t))
    {
        _input = analogInput;
        _midiChannel = midiChannel;
        _midiNumber = midiNumber;
        _fnCC = funCC;
    }

    Pot() = default;

    void read()
    {
        inputStr_t in;
        in.midiChannel = _midiChannel;
        in.midiNumber = _midiNumber;
        in.funCC = _fnCC;
        _input->read(in);
    }

    void setMidiChannel(uint8_t midiChannel)
    {
        _midiChannel = midiChannel;
    }

protected:
    AnalogInput *_input;
    void (*_fnCC)(uint8_t, uint8_t, uint8_t);
    uint8_t _midiChannel;
    uint8_t _midiNumber;
};

#endif