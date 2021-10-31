

#pragma once
#ifndef PAD_STR_H
#define PAD_STR_H

#include <md_pad_func.h>

struct PadAggr
{
    MDPadFunc* funcs;
    uint8_t midiChannel;
    void (*funcOn)(uint8_t, uint8_t, uint8_t);
    void (*funcOff)(uint8_t, uint8_t, uint8_t);
};

#endif // PAD_STR_H
