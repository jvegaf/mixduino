#pragma once

#include <Arduino.h>
#include "md_enums.hpp"

class Pad
{
public:

    Pad(const uint8_t* notes, void(*Func)(uint8_t, uint8_t, uint8_t))
    : midi_notes(notes), noteFunc(Func) { }

    void changeMode();

    //todo: implement
    void handleEvent(uint8_t id, State state);

    uint8_t* getHotcues()
    {
        return this->hotcues;
    }

    void setHotCueType(uint8_t pos, uint8_t type);

    void sendNote(uint8_t element, State state);

private:
const uint8_t* midi_notes;
void(*noteFunc)(uint8_t, uint8_t, uint8_t);
uint8_t* hotcues{0};
Mode pad_mode{Mode::HotCues};
};