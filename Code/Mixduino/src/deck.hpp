#ifndef DECK_H
#define DECK_H

#pragma once
#include <Arduino.h>


class Deck
{
public:
    Deck(const uint8_t* notes, void(*Func)(uint8_t, uint8_t, uint8_t))
    : midi_notes(notes), FuncPtr(Func) { }
    
private:
    const uint8_t* midi_notes;
    void(*FuncPtr)(uint8_t, uint8_t, uint8_t);
};

#endif