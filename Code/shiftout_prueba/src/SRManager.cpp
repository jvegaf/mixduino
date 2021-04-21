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
const byte datavalues[] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
const int latchPin = 8;
const int clockPin = 13;
const int dataPin = 11;

SRManager::SRManager(byte *cNums)
{
    this->ccNums = cNums;
    this->nRegisters = sizeof(cNums);
    this->regValues = new byte[nRegisters];
    this->cclastValues = {0};
}

SRManager::~SRManager()
{
}

void SRManager::begin()
{
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    this->clearAll();
}

void SRManager::clearAll()
{
    digitalWrite(latchPin, 0);
    for (int i = 0; i < nRegisters; i++)
    {
        shiftOut(0x00);
    }
    digitalWrite(latchPin, 1);
}

void SRManager::shiftOut(byte myDataOut)
{
    // This shifts 8 bits out MSB first,

    //on the rising edge of the clock,

    //clock idles low

    //internal function setup

    int i = 0;

    int pinState;

    //clear everything out just in case to

    //prepare shift register for bit shifting

    digitalWrite(dataPin, 0);

    digitalWrite(clockPin, 0);

    //for each bit in the byte myDataOut&#xFFFD;

    //NOTICE THAT WE ARE COUNTING DOWN in our for loop

    //This means that %00000001 or "1" will go through such

    //that it will be pin Q0 that lights.

    for (i = 7; i >= 0; i--)
    {

        digitalWrite(clockPin, 0);

        //if the value passed to myDataOut and a bitmask result

        // true then... so if we are at i=6 and our value is

        // %11010100 it would the code compares it to %01000000

        // and proceeds to set pinState to 1.

        if (myDataOut & (1 << i))
        {

            pinState = 1;
        }

        else
        {

            pinState = 0;
        }

        //Sets the pin to HIGH or LOW depending on pinState

        digitalWrite(dataPin, pinState);

        //register shifts bits on upstroke of clock pin

        digitalWrite(clockPin, 1);

        //zero the data pin after shift to prevent bleed through
        digitalWrite(dataPin, 0);
    }

    //stop shifting

    digitalWrite(clockPin, 0);
}

void SRManager::shiftAll()
{
    digitalWrite(latchPin, 0);
    for (int i = 0; i < nRegisters; i++)
    {
        shiftOut(regValues[i]);
    }
    digitalWrite(latchPin, 1);
}

void SRManager::handleControlChange(byte number, byte value)
{
    int value_ = value;

    for (int i=0; i<nRegisters; i++) {
        if(ccNums[i] == number){
            if (value_ != cclastValues[i]){
                regValues[i] = datavalues[value_];
                cclastValues[i] = value;
            }
            break;
        }
    }

    shiftAll();
}