#pragma once
#include <Arduino.h>

#include "components_def.h"


//////////////////////////////////////
// MUX LEFT BUTTONS PINS

const uint8_t sw_cue_b     = static_cast<uint8_t>(Mixer::CueB);             // pos0
const uint8_t sw_cue_a     = static_cast<uint8_t>(Mixer::CueA);             // pos1
const uint8_t sw_shift     = static_cast<uint8_t>(Mixer::Shift);            // pos2
const uint8_t sw_loop_l    = static_cast<uint8_t>(DeckLeft::Loop);          // pos3
const uint8_t sw_sync_l    = static_cast<uint8_t>(DeckLeft::Sync);          // pos4
const uint8_t sw_padmode_l = static_cast<uint8_t>(DeckLeft::ModeSelector);  // pos5
const uint8_t sw_play_l    = static_cast<uint8_t>(DeckLeft::Play);          // pos6
const uint8_t sw_cue_l     = static_cast<uint8_t>(DeckLeft::Cue);           // pos7
const uint8_t sw_lpad_8    = static_cast<uint8_t>(PadLeft::P_8);            // pos8
const uint8_t sw_lpad_4    = static_cast<uint8_t>(PadLeft::P_4);            // pos9
const uint8_t sw_lpad_7    = static_cast<uint8_t>(PadLeft::P_7);            // pos10
const uint8_t sw_lpad_3    = static_cast<uint8_t>(PadLeft::P_3);            // pos11
const uint8_t sw_lpad_2    = static_cast<uint8_t>(PadLeft::P_2);            // pos12
const uint8_t sw_lpad_6    = static_cast<uint8_t>(PadLeft::P_6);            // pos13
const uint8_t sw_lpad_1    = static_cast<uint8_t>(PadLeft::P_1);            // pos14
const uint8_t sw_lpad_5    = static_cast<uint8_t>(PadLeft::P_5);            // pos15



const uint8_t left_mux_el[] = {
    sw_cue_b,
    sw_cue_a,
    sw_shift,
    sw_loop_l,
    sw_sync_l,
    sw_padmode_l,
    sw_play_l,
    sw_cue_l,
    sw_lpad_8,
    sw_lpad_4,
    sw_lpad_7,
    sw_lpad_3,
    sw_lpad_2,
    sw_lpad_6,
    sw_lpad_1,
    sw_lpad_5
};


const uint8_t t_mux_els = 16;

const uint8_t kEmptyEl = 999;

//////////////888////////////////////////
// MUX RIGHT BUTTONS

const uint8_t sw_cue_r     = static_cast<uint8_t>(DeckRight::Cue);          // pos0;
const uint8_t sw_play_r    = static_cast<uint8_t>(DeckRight::Play);         // pos1;
const uint8_t sw_padmode_r = static_cast<uint8_t>(DeckRight::ModeSelector); // pos2;
const uint8_t sw_loop_r    = static_cast<uint8_t>(DeckRight::Loop);         // pos3;
const uint8_t sw_empty     = static_cast<uint8_t>(kEmptyEl);                // pos4;
const uint8_t sw_cue_c     = static_cast<uint8_t>(Mixer::CueC);             // pos5;
const uint8_t sw_sync_r    = static_cast<uint8_t>(DeckRight::Sync);         // pos6;
const uint8_t sw_deck_sel  = static_cast<uint8_t>(DeckRight::ModeSelector); // pos7;
const uint8_t sw_rpad_8    = static_cast<uint8_t>(PadRight::P_8);           // pos8;
const uint8_t sw_rpad_4    = static_cast<uint8_t>(PadRight::P_4);           // pos9;
const uint8_t sw_rpad_7    = static_cast<uint8_t>(PadRight::P_7);           // pos10;
const uint8_t sw_rpad_3    = static_cast<uint8_t>(PadRight::P_3);           // pos11;
const uint8_t sw_rpad_2    = static_cast<uint8_t>(PadRight::P_2);           // pos12;
const uint8_t sw_rpad_6    = static_cast<uint8_t>(PadRight::P_6);           // pos13;
const uint8_t sw_rpad_1    = static_cast<uint8_t>(PadRight::P_1);           // pos14;
const uint8_t sw_rpad_5    = static_cast<uint8_t>(PadRight::P_5);           // pos15;

const uint8_t right_mux_el[] = {
    sw_cue_r,
    sw_play_r,
    sw_padmode_r,
    sw_loop_r,
    sw_empty,
    sw_cue_c,
    sw_sync_r,
    sw_deck_sel,
    sw_rpad_8,
    sw_rpad_4,
    sw_rpad_7,
    sw_rpad_3,
    sw_rpad_2,
    sw_rpad_6,
    sw_rpad_1,
    sw_rpad_5,
};


const uint8_t aswfxl_3 = static_cast<uint8_t>(FxUnit1::Button3);
const uint8_t aswfxl_2 = static_cast<uint8_t>(FxUnit1::Button2);
const uint8_t aswfxl_1 = static_cast<uint8_t>(FxUnit1::Button1);
const uint8_t aswfxr_3 = static_cast<uint8_t>(FxUnit2::Button3);
const uint8_t aswfxr_2 = static_cast<uint8_t>(FxUnit2::Button2);
const uint8_t aswfxr_1 = static_cast<uint8_t>(FxUnit2::Button1);
const uint8_t asw_br_right = static_cast<uint8_t>(Browser::RightBtn);
const uint8_t asw_br_left = static_cast<uint8_t>(Browser::LeftBtn);
const uint8_t asw_br_back = static_cast<uint8_t>(Browser::BackBtn);
const uint8_t asw_br_preview = static_cast<uint8_t>(Browser::PreviewBtn);


const uint8_t ard_elements[] = {
     aswfxl_3,
     aswfxl_2,
     aswfxl_1,
     aswfxr_3,
     aswfxr_2,
     aswfxr_1,
     asw_br_right,
     asw_br_left,
     asw_br_back,
     asw_br_preview
};


