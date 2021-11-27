#pragma once
#ifndef MD_INPUT_STR_H
#define MD_INPUT_STR_H
#include <Arduino.h>

struct inputStr
{
    uint8_t midiChannel;
    uint8_t midiNumber;
    void (*funOn)(uint8_t, uint8_t, uint8_t);
	void (*funOff)(uint8_t, uint8_t, uint8_t);
    void (*funCC)(uint8_t, uint8_t, uint8_t);
    void (*cbackFun)();
    void (*cbackMode)(uint8_t);
};

typedef struct inputStr inputStr_t;

#endif