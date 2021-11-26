#pragma once
#ifndef MD_BUTTONMIDI_H
#define MD_BUTTONMIDI_H
#include "Button.h"

class ButtonFunc : public Button
{

public:

    ButtonFunc(
        DigitalInput* input, 
        Output* output, 
        uint8_t midiChannel, 
        uint8_t midiNote,
        void (*funcOn)(uint8_t, uint8_t, uint8_t), 
        void (*funcOff)(uint8_t, uint8_t, uint8_t) 
    )
    : Button(input, output)
    {
        _midiChannel = midiChannel;
        _midiNote = midiNote;
        _fnOn = funcOn;
        _fnOff = funcOff;
    }

    void read() override
    {
        inputStr_t inStr;
        inStr.funOn = _fnOn;
        inStr.funOff = _fnOff;
        inStr.midiChannel = _midiChannel;
        inStr.midiNumber = _midiNote;
        _input->read(inStr);
    }

protected:
    void (*_fnOn)(uint8_t, uint8_t, uint8_t); 
    void (*_fnOff)(uint8_t, uint8_t, uint8_t);
    uint8_t _midiChannel;
    uint8_t _midiNote;
};

#endif