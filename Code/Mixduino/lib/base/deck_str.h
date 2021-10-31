#pragma once
#ifndef DECK_STR_H
#define DECK_STR_H

#include <md_mode_func.h>
#include <Pad.h>


struct DeckAggr
{
    Pad* pp;
    MDModeFunc* modeFunc;
    MDFunc* funcs;
    uint8_t midiChannel;
    void (*funcOn)(uint8_t, uint8_t, uint8_t);
    void (*funcOff)(uint8_t, uint8_t, uint8_t);
};


#endif // DECK_STR_H
