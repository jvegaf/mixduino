#ifndef ARDUINO_MODULES_H

#define ARDUINO_MODULES_H
#include <Arduino.h>
#include "sw_muxmap.h"
#include "feedback.h"
#include "MuxBtn.h"
#include "Npixel.h"
#include "MDFunc.h"

#pragma once

uint8_t const T_DECK_FUNCS_RGB = 9U;
uint8_t const T_DECK_FUNCS = 12U;

struct DeckAggregate
{
    MDFunc* modeFunc;
    MDFunc* deckFuncs;
};


///////////////////////////
// DECK LEFT

MuxBtn cueLeftBtn(MUXSW_LEFT_SIG, SWCUE_L);
Led cueLeftLed(FEEDBACK_LEFT, OUT_CUE_DECK_A);
MDFunc cueLeftFunc = {&cueLeftBtn, &cueLeftLed};

MuxBtn PlayLeftBtn(MUXSW_LEFT_SIG, SWPLAY_L);
Led PlayLeftLed(FEEDBACK_LEFT, OUT_PLAY_DECK_A);
MDFunc PlayLeftFunc = {&PlayLeftBtn, &PlayLeftLed};

MuxBtn ModeLeftBtn(MUXSW_LEFT_SIG, SWMODE_L);
Npixel ModeLeftLed(NP_MODE_L);
MDFunc ModeLeftFunc = {&ModeLeftBtn, &ModeLeftLed};

MuxBtn SyncLeftBtn(MUXSW_LEFT_SIG, SWSYNC_L);
Npixel SyncLeftLed(NP_SYNC_L);
MDFunc SyncLeftFunc = {&SyncLeftBtn, &SyncLeftLed};

MuxBtn LoopLeftBtn(MUXSW_LEFT_SIG, SWLOOP_L);
Led LoopLeftLed(FEEDBACK_LEFT, OUT_LOOP_DECK_A);
MDFunc LoopLeftFunc = {&LoopLeftBtn, &LoopLeftLed};

MuxBtn ShiftBtn(MUXSW_LEFT_SIG, SWSHIFT);

MuxBtn Pad1LeftBtn(MUXSW_LEFT_SIG, SWPADL1);
Npixel Pad1LeftLed(NP_PADL1);
MDFunc Pad1LeftFunc = {&Pad1LeftBtn, &Pad1LeftLed};

MuxBtn Pad2LeftBtn(MUXSW_LEFT_SIG, SWPADL2);
Npixel Pad2LeftLed(NP_PADL2);
MDFunc Pad2LeftFunc = {&Pad2LeftBtn, &Pad2LeftLed};

MuxBtn Pad3LeftBtn(MUXSW_LEFT_SIG, SWPADL3);
Npixel Pad3LeftLed(NP_PADL3);
MDFunc Pad3LeftFunc = {&Pad3LeftBtn, &Pad3LeftLed};

MuxBtn Pad4LeftBtn(MUXSW_LEFT_SIG, SWPADL4);
Npixel Pad4LeftLed(NP_PADL4);
MDFunc Pad4LeftFunc = {&Pad4LeftBtn, &Pad4LeftLed};

MuxBtn Pad5LeftBtn(MUXSW_LEFT_SIG, SWPADL5);
Npixel Pad5LeftLed(NP_PADL5);
MDFunc Pad5LeftFunc = {&Pad5LeftBtn, &Pad5LeftLed};

MuxBtn Pad6LeftBtn(MUXSW_LEFT_SIG, SWPADL6);
Npixel Pad6LeftLed(NP_PADL6);
MDFunc Pad6LeftFunc = {&Pad6LeftBtn, &Pad6LeftLed};

MuxBtn Pad7LeftBtn(MUXSW_LEFT_SIG, SWPADL7);
Npixel Pad7LeftLed(NP_PADL7);
MDFunc Pad7LeftFunc = {&Pad7LeftBtn, &Pad7LeftLed};

MuxBtn Pad8LeftBtn(MUXSW_LEFT_SIG, SWPADL8);
Npixel Pad8LeftLed(NP_PADL8);
MDFunc Pad8LeftFunc = {&Pad8LeftBtn, &Pad8LeftLed};

MDFunc deckLeftFuncs[] = {
    Pad1LeftFunc,
    Pad2LeftFunc,
    Pad3LeftFunc,
    Pad4LeftFunc,
    Pad5LeftFunc,
    Pad6LeftFunc,
    Pad7LeftFunc,
    Pad8LeftFunc,
    SyncLeftFunc,
    cueLeftFunc,
    PlayLeftFunc,
    LoopLeftFunc
    };

DeckAggregate deckLeftAggr = {
    &ModeLeftFunc,
    deckLeftFuncs
};

///////////////////////////
// DECK RIGHT

MuxBtn CueRightBtn(MUXSW_RIGHT_SIG, SWCUE_R);
Led CueRightLed(FEEDBACK_RIGHT, OUT_CUE_DECK_A);
MDFunc cueRightFunc = {&CueRightBtn, &CueRightLed};

MuxBtn PlayRightBtn(MUXSW_RIGHT_SIG, SWPLAY_R);
Led PlayRightLed(FEEDBACK_RIGHT, OUT_PLAY_DECK_A);
MDFunc PlayRightFunc = {&PlayRightBtn, &PlayRightLed};

MuxBtn ModeRightBtn(MUXSW_RIGHT_SIG, SWMODE_R);
Npixel ModeRightLed(NP_MODE_R);
MDFunc ModeRightFunc = {&ModeRightBtn, &ModeRightLed};

MuxBtn SyncRightBtn(MUXSW_RIGHT_SIG, SWSYNC_R);
Npixel SyncRightLed(NP_SYNC_R);
MDFunc SyncRightFunc = {&SyncRightBtn, &SyncRightLed};

MuxBtn LoopRightBtn(MUXSW_RIGHT_SIG, SWLOOP_R);
Led LoopRightLed(FEEDBACK_RIGHT, OUT_LOOP_DECK_A);
MDFunc LoopRightFunc = {&LoopRightBtn, &LoopRightLed};

MuxBtn DeckSelectBtn(MUXSW_RIGHT_SIG, SWDECK_SEL);
Npixel DeckSelectLed(NP_DECK_SEL);
MDFunc DeckSelectFunc = {&DeckSelectBtn, &DeckSelectLed};

MuxBtn Pad1RightBtn(MUXSW_RIGHT_SIG, SWPADR1);
Npixel Pad1RightLed(NP_PADR1);
MDFunc Pad1RightFunc = {&Pad1RightBtn, &Pad1RightLed};

MuxBtn Pad2RightBtn(MUXSW_RIGHT_SIG, SWPADR2);
Npixel Pad2RightLed(NP_PADR2);
MDFunc Pad2RightFunc = {&Pad2RightBtn, &Pad2RightLed};

MuxBtn Pad3RightBtn(MUXSW_RIGHT_SIG, SWPADR3);
Npixel Pad3RightLed(NP_PADR3);
MDFunc Pad3RightFunc = {&Pad3RightBtn, &Pad3RightLed};

MuxBtn Pad4RightBtn(MUXSW_RIGHT_SIG, SWPADR4);
Npixel Pad4RightLed(NP_PADR4);
MDFunc Pad4RightFunc = {&Pad4RightBtn, &Pad4RightLed};

MuxBtn Pad5RightBtn(MUXSW_RIGHT_SIG, SWPADR5);
Npixel Pad5RightLed(NP_PADR5);
MDFunc Pad5RightFunc = {&Pad5RightBtn, &Pad5RightLed};

MuxBtn Pad6RightBtn(MUXSW_RIGHT_SIG, SWPADR6);
Npixel Pad6RightLed(NP_PADR6);
MDFunc Pad6RightFunc = {&Pad6RightBtn, &Pad6RightLed};

MuxBtn Pad7RightBtn(MUXSW_RIGHT_SIG, SWPADR7);
Npixel Pad7RightLed(NP_PADR7);
MDFunc Pad7RightFunc = {&Pad7RightBtn, &Pad7RightLed};

MuxBtn Pad8RightBtn(MUXSW_RIGHT_SIG, SWPADR8);
Npixel Pad8RightLed(NP_PADR8);
MDFunc Pad8RightFunc = {&Pad8RightBtn, &Pad8RightLed};

MDFunc deckRightFuncs[] = {
    Pad1RightFunc,
    Pad2RightFunc,
    Pad3RightFunc,
    Pad4RightFunc,
    Pad5RightFunc,
    Pad6RightFunc,
    Pad7RightFunc,
    Pad8RightFunc,
    SyncRightFunc,
    cueRightFunc,
    PlayRightFunc,
    LoopRightFunc
    };


DeckAggregate deckRightAggr = {
    &ModeRightFunc,
    deckRightFuncs
};

#endif