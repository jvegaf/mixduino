#pragma once

#include <Arduino.h>
#include "midi_values.h"


/////////////////////////////////////////
// CHN

const uint8_t leds_out_ch    = 1;
const uint8_t sw_in_ch       = 2;
const uint8_t pad_in_ch      = 3;
const uint8_t pad_out_ch     = 4;
const uint8_t hotcues_ch     = 5;
const uint8_t loop_size_ch   = 6;
const uint8_t beatjump_ch    = 7;
const uint8_t tempo_range_ch = 8;



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
const uint8_t	BROWSER_R    = 27;
const uint8_t	BROWSER_L    = 28;
const uint8_t	BR_PREVIEW   = 29;
const uint8_t	BR_BACK      = 30;


// channel 3 

const uint8_t LEVEL_DECK_A        = 0;
const uint8_t LEVEL_DECK_B        = 1;
const uint8_t LEVEL_DECK_C        = 2;
const uint8_t MASTER_OUT_L        = 3;
const uint8_t MASTER_OUT_R        = 4;

const uint8_t pad_A_notes[] = {
  km_C_0,
  km_Cs_0,
  km_D_0,
  km_Ds_0,
  km_E_0,
  km_F_0,
  km_Fs_0,
  km_G_0
};

const uint8_t pad_B_notes[] = {
  km_Gs_0,
  km_A_0,
  km_As_0,
  km_B_0,
  km_C_1,
  km_Cs_1,
  km_D_1,
  km_Ds_1
};

const uint8_t pad_C_notes[] = {
  km_G_1,
  km_Ds_0,
  km_E_0,
  km_F_0,
  km_Gs_1,
  km_A_1, 
  km_As_1,
  km_B_1 
};



const uint8_t deck_A_notes[] =  {
  km_E_1,
  km_F_1,
  km_Fs_1,
  km_G_1
};

const uint8_t deck_B_notes[] =  {
  km_A_1,
  km_As_1,
  km_B_1,
  km_C_2
};


const uint8_t deck_C_notes[] = {
  km_Cs_2,
  km_D_2,
  km_Ds_2,
  km_E_2
};

 
const uint8_t lfx_notes[] =  {
  km_D_0,
  km_Cs_0,
  km_C_0,
};

const uint8_t rfx_notes[] =   {
  km_D_1,
  km_Cs_1,
  km_C_1
};

const uint8_t mixer_notes[] = {
  km_Cs_0,
  km_D_0,
  km_Ds_0,
  km_E_1,
  km_Ds_1,
  km_B_1,
  km_C_2  
};


enum class Mode : uint8_t
{
    HotCues = hotcues_ch,
    Loop = loop_size_ch,
    Beatjump = beatjump_ch,
    TempoRange = tempo_range_ch
};
