#include "SRManager.h"
////////////////////////////////////////
//   BIN      HEX       INT
// 00000000   00        0
// 00000001   01        1
// 00000011   03        3
// 00000111   07        7
// 00001111   0F       15
// 00011111   1F       31
// 00111111   3F       63
// 01111111   7F      127
// 11111111   FF      255
const int dataValues[] = {
    0,
    1,
    3,
    7,
    15,
    31,
    63,
    127,
    255,
    511,
    1023,
    2047,
    4095,
    8191,
    16383,
    32767};
const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

SRManager::SRManager() {}

void SRManager::begin()
{
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    this->setLevel(0);
}

void SRManager::setLevel(uint8_t level)
{
    int dataLevel = dataValues[level];
    digitalWrite(latchPin, LOW);
    // shift out lowbyte
    shiftOut(dataPin, clockPin, LSBFIRST, dataLevel);
    // shift out highbyte
    shiftOut(dataPin, clockPin, LSBFIRST, (dataLevel >> 8));
    digitalWrite(latchPin, HIGH);
}
