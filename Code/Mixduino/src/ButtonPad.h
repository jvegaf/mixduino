#pragma once
#ifndef MD_BUTTONPAD_H
#define MD_BUTTONPAD_H
#include "ButtonMidi.h"

class ButtonPad : public ButtonFunc
{

public:

    ButtonPad(
        Input* input, 
        Output* output, 
        uint8_t midiChannel, 
        uint8_t midiNote,
        void (*funcOn)(uint8_t, uint8_t, uint8_t), 
        void (*funcOff)(uint8_t, uint8_t, uint8_t) )
        : ButtonFunc(input, output, midiChannel, midiNote, funcOn, funcOff)
        {

        }

    void setNote(uint8_t note)
    {
        _midiNote = note;
    }
};

#endif