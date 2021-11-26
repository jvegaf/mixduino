#pragma once
#ifndef MD_INPUT_STR_H
#define MD_INPUT_STR_H
#include <Arduino.h>

struct inputStr
{
    uint8_t midiChannel;
    uint8_t midiNote;
    void (*funOn)(uint8_t, uint8_t, uint8_t);
	void (*funOff)(uint8_t, uint8_t, uint8_t);
    void (*calbackFun)();
};

typedef struct inputStr inputStr_t;

#endif