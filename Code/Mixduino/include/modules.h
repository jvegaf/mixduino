#define ARDUINO_MODULES_H
#include <Arduino.h>
#include "sw_muxmap.h"
#include "feedback.h"
#include "MuxBtn.h"
#include "Led.h"
#include "Npixel.h"

#pragma once

///////////////////////////
// DECK LEFT
// INPUTS

MuxBtn CueLeftBtn(MUXSW_LEFT_SIG, SWCUE_L);
MuxBtn PlayLeftBtn(MUXSW_LEFT_SIG, SWPLAY_L);
MuxBtn ModeLeftBtn(MUXSW_LEFT_SIG, SWMODE_L);
MuxBtn SyncLeftBtn(MUXSW_LEFT_SIG, SWSYNC_L);
MuxBtn LoopLeftBtn(MUXSW_LEFT_SIG, SWLOOP_L);
MuxBtn ShiftBtn(MUXSW_LEFT_SIG, SWSHIFT);
MuxBtn Pad1LeftBtn(MUXSW_LEFT_SIG, SWPADL1);
MuxBtn Pad2LeftBtn(MUXSW_LEFT_SIG, SWPADL2);
MuxBtn Pad3LeftBtn(MUXSW_LEFT_SIG, SWPADL3);
MuxBtn Pad4LeftBtn(MUXSW_LEFT_SIG, SWPADL4);
MuxBtn Pad5LeftBtn(MUXSW_LEFT_SIG, SWPADL5);
MuxBtn Pad6LeftBtn(MUXSW_LEFT_SIG, SWPADL6);
MuxBtn Pad7LeftBtn(MUXSW_LEFT_SIG, SWPADL7);
MuxBtn Pad8LeftBtn(MUXSW_LEFT_SIG, SWPADL8);

MuxBtn deckLeftBtns[] = {
    CueLeftBtn,
    PlayLeftBtn,
    SyncLeftBtn,
    LoopLeftBtn,
    ShiftBtn,
    Pad1LeftBtn,
    Pad2LeftBtn,
    Pad3LeftBtn,
    Pad4LeftBtn,
    Pad5LeftBtn,
    Pad6LeftBtn,
    Pad7LeftBtn,
    Pad8LeftBtn
};

int totalLeftBtns = 13;

// OUTPUTS
Led CueLeftLed(FEEDBACK_LEFT, OUT_CUE_DECK_A);
Led PlayLeftLed(FEEDBACK_LEFT, OUT_PLAY_DECK_A);
Led LoopLeftLed(FEEDBACK_LEFT, OUT_LOOP_DECK_A);

const Led LeftLeds[] = {
    CueLeftLed,
    PlayLeftLed,
    LoopLeftLed
};

int totalLeftLeds = 3;

Npixel ModeLeftLed(NP_MODE_L);
Npixel SyncLeftLed(NP_SYNC_L);
Npixel Pad1LeftLed(NP_PADL1);
Npixel Pad2LeftLed(NP_PADL2);
Npixel Pad3LeftLed(NP_PADL3);
Npixel Pad4LeftLed(NP_PADL4);
Npixel Pad5LeftLed(NP_PADL5);
Npixel Pad6LeftLed(NP_PADL6);
Npixel Pad7LeftLed(NP_PADL7);
Npixel Pad8LeftLed(NP_PADL8);

const Npixel DeckLeftNPs[] = {
    ModeLeftLed,
    SyncLeftLed,
    Pad1LeftLed,
    Pad2LeftLed,
    Pad3LeftLed,
    Pad4LeftLed,
    Pad5LeftLed,
    Pad6LeftLed,
    Pad7LeftLed,
    Pad8LeftLed};

int totalLeftNpixels = 10;
///////////////////////////
// DECK RIGHT
// INPUTS

MuxBtn CueRightBtn(MUXSW_RIGHT_SIG, SWCUE_R);
MuxBtn PlayRightBtn(MUXSW_RIGHT_SIG, SWPLAY_R);
MuxBtn ModeRightBtn(MUXSW_RIGHT_SIG, SWMODE_R);
MuxBtn SyncRightBtn(MUXSW_RIGHT_SIG, SWSYNC_R);
MuxBtn LoopRightBtn(MUXSW_RIGHT_SIG, SWLOOP_R);
MuxBtn DeckSelectBtn(MUXSW_RIGHT_SIG, SWDECK_SEL);
MuxBtn Pad1RightBtn(MUXSW_RIGHT_SIG, SWPADR1);
MuxBtn Pad2RightBtn(MUXSW_RIGHT_SIG, SWPADR2);
MuxBtn Pad3RightBtn(MUXSW_RIGHT_SIG, SWPADR3);
MuxBtn Pad4RightBtn(MUXSW_RIGHT_SIG, SWPADR4);
MuxBtn Pad5RightBtn(MUXSW_RIGHT_SIG, SWPADR5);
MuxBtn Pad6RightBtn(MUXSW_RIGHT_SIG, SWPADR6);
MuxBtn Pad7RightBtn(MUXSW_RIGHT_SIG, SWPADR7);
MuxBtn Pad8RightBtn(MUXSW_RIGHT_SIG, SWPADR8);

const MuxBtn DeckRightBtns[] = {
    CueRightBtn,
    PlayRightBtn,
    SyncRightBtn,
    LoopRightBtn,
    ShiftBtn,
    Pad1RightBtn,
    Pad2RightBtn,
    Pad3RightBtn,
    Pad4RightBtn,
    Pad5RightBtn,
    Pad6RightBtn,
    Pad7RightBtn,
    Pad8RightBtn};

int totalRightBtns = 13;

// OUTPUTS
Led CueRightLed(FEEDBACK_RIGHT, OUT_CUE_DECK_A);
Led PlayRightLed(FEEDBACK_RIGHT, OUT_PLAY_DECK_A);
Led LoopRightLed(FEEDBACK_RIGHT, OUT_LOOP_DECK_A);

const Led RightLeds[] = {
    CueRightLed,
    PlayRightLed,
    LoopRightLed
};

int totalRightLeds = 3

Npixel ModeRightLed(NP_MODE_R);
Npixel SyncRightLed(NP_SYNC_R);
Npixel DeckSelectLed(NP_DECK_SEL);
Npixel Pad1RightLed(NP_PADR1);
Npixel Pad2RightLed(NP_PADR2);
Npixel Pad3RightLed(NP_PADR3);
Npixel Pad4RightLed(NP_PADR4);
Npixel Pad5RightLed(NP_PADR5);
Npixel Pad6RightLed(NP_PADR6);
Npixel Pad7RightLed(NP_PADR7);
Npixel Pad8RightLed(NP_PADR8);

const Npixel DeckRightNPs[] = {
    ModeRightLed,
    SyncRightLed,
    DeckSelectLed,
    Pad1RightLed,
    Pad2RightLed,
    Pad3RightLed,
    Pad4RightLed,
    Pad5RightLed,
    Pad6RightLed,
    Pad7RightLed,
    Pad8RightLed};

int totalRightNpixels = 11;