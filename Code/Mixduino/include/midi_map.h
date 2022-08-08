
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>

#pragma once


const uint8_t kfst_note = 12;
const uint8_t lpad_fnote = kfst_note;
const uint8_t rpad_fnote = 20;
const uint8_t pbtn_l_fnote = 15;
const uint8_t pbtn_r_fnote = 20;
const uint8_t sbtn_l_fnote = 28;
const uint8_t sbtn_r_fnote = 30;



/////////////////////////////////////////
// CHN

const uint8_t leds_out_ch    = 1;
const uint8_t sw_in_ch       = 2;
const uint8_t pad_in_ch      = 3;
const uint8_t pad_out_ch     = 4;
const uint8_t hotcues_ch     = 5;
const uint8_t loop_size_ch   = 6;
const uint8_t beatjump_ch    = 7;
const uint8_t range_sel_ch   = 8;



/////////////////////////////////////////
// OUTS


const uint8_t FXL_BTN_3    = 12;
const uint8_t FXL_BTN_2    = 13;
const uint8_t FXL_BTN_1    = 14;
const uint8_t PLAY_L       = 15;
const uint8_t CUE_L        = 16;
const uint8_t LOOP_L       = 17;
const uint8_t CUE_B        = 18;
const uint8_t CUE_A        = 19;
const uint8_t CUE_C        = 20;
const uint8_t CUE_R        = 21;
const uint8_t PLAY_R       = 22;
const uint8_t LOOP_R       = 23;
const uint8_t FXR_BTN_3    = 24;
const uint8_t FXR_BTN_2    = 25;
const uint8_t FXR_BTN_1    = 26;
const uint8_t	BROWSER_R = 27;
const uint8_t	BROWSER_L = 28;
const uint8_t	BR_PREVIEW = 29;
const uint8_t	BR_BACK    = 30;

uint8_t const btn_kit_set[] = {
  FXL_BTN_3,
  FXL_BTN_2,
  FXL_BTN_1,
  FXR_BTN_3,
  FXR_BTN_2,
  FXR_BTN_1,
  BROWSER_R,
  BROWSER_L,
  BR_PREVIEW,
  BR_BACK
};



// Control Changes

// channel 1

const uint8_t HOTCUE_1T_DK_A      = 0; 
const uint8_t HOTCUE_2T_DK_A      = 1;
const uint8_t HOTCUE_3T_DK_A      = 2;
const uint8_t HOTCUE_4T_DK_A      = 3;
const uint8_t HOTCUE_5T_DK_A      = 4;
const uint8_t HOTCUE_6T_DK_A      = 5;
const uint8_t HOTCUE_7T_DK_A      = 6;
const uint8_t HOTCUE_8T_DK_A      = 7; 
const uint8_t RANGE_SELECTOR_DK_A = 8; 
const uint8_t SYNC_ON_DECK_A      = 9; 
const uint8_t HOTCUE_1T_DK_B      = 10;
const uint8_t HOTCUE_2T_DK_B      = 11;
const uint8_t HOTCUE_3T_DK_B      = 12;
const uint8_t HOTCUE_4T_DK_B      = 13;
const uint8_t HOTCUE_5T_DK_B      = 14;
const uint8_t HOTCUE_6T_DK_B      = 15;
const uint8_t HOTCUE_7T_DK_B      = 16;
const uint8_t HOTCUE_8T_DK_B      = 17;
const uint8_t DECK_B_C_SELECTION  = 18;
const uint8_t RANGE_SELECTOR_DK_B = 19;
const uint8_t SYNC_ON_DECK_B      = 20;

// channel 3 

const uint8_t LEVEL_DECK_A        = 0;
const uint8_t LEVEL_DECK_B        = 1;
const uint8_t LEVEL_DECK_C        = 2;
const uint8_t MASTER_OUT_L        = 3;
const uint8_t MASTER_OUT_R        = 4;

#endif
