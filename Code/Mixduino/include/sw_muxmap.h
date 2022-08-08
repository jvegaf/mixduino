#ifndef __SW_MUXMAP_H__
#define __SW_MUXMAP_H__





#include <Arduino.h>


//////////////////////////////////////
// MUX LEFT BUTTONS PINS

const uint8_t sw_cue_b    = 0;
const uint8_t sw_cue_a    = 1;
const uint8_t sw_shift    = 2;
const uint8_t sw_loop_l   = 3;
const uint8_t sw_sync_l   = 4;
const uint8_t sw_range_l  = 5;
const uint8_t sw_play_l   = 6;
const uint8_t sw_cue_l    = 7;
const uint8_t sw_lpad_8   = 8;
const uint8_t sw_lpad_4   = 9;
const uint8_t sw_lpad_7   = 10;
const uint8_t sw_lpad_3   = 11;
const uint8_t sw_lpad_2   = 12;
const uint8_t sw_lpad_6   = 13;
const uint8_t sw_lpad_1   = 14;
const uint8_t sw_lpad_5   = 15;

const uint8_t SwMuxLeftSetPrimary[] = {
    sw_play_l,
    sw_cue_l,
    sw_loop_l,
    sw_cue_b,
    sw_cue_a
};

const uint8_t SwMuxLeftSetSencondary[] = {
    sw_shift,
    sw_sync_l
};

const uint8_t t_mleft_sec = 2;
const uint8_t t_mleft_pri = 5;

const uint8_t SwMuxLeftPads[] = {
    sw_lpad_1,
    sw_lpad_2,
    sw_lpad_3,
    sw_lpad_4,
    sw_lpad_5,
    sw_lpad_6,
    sw_lpad_7,
    sw_lpad_8
};




//////////////////////////////////////
// MUX RIGHT BUTTONS

const uint8_t sw_cue_r     = 0;
const uint8_t sw_play_r    = 1;
const uint8_t sw_range_r   = 2;
const uint8_t sw_loop_r    = 3;
const uint8_t sw_cue_c     = 5;
const uint8_t sw_sync_r    = 6;
const uint8_t sw_deck_sel  = 7;
const uint8_t sw_rpad_8    = 8;
const uint8_t sw_rpad_4    = 9;
const uint8_t sw_rpad_7    = 10;
const uint8_t sw_rpad_3    = 11;
const uint8_t sw_rpad_2    = 12;
const uint8_t sw_rpad_6    = 13;
const uint8_t sw_rpad_1    = 14;
const uint8_t sw_rpad_5    = 15;


const uint8_t SWMuxRightSetPrimary[] = {
    sw_cue_r,
    sw_play_r,
    sw_loop_r,
    sw_cue_c
};

const uint8_t SWMuxRightSetSecondary[] = {
    sw_sync_r
};

const uint8_t t_mright_pri = 4;
const uint8_t t_mright_sec = 1;

const uint8_t SWMuxRightPads[] = {
    sw_rpad_1,
    sw_rpad_2,
    sw_rpad_3,
    sw_rpad_4,
    sw_rpad_5,
    sw_rpad_6,
    sw_rpad_7,
    sw_rpad_8
};

const uint8_t t_pads = 8;

#endif // __SW_MUXMAP_H__