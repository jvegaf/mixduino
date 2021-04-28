#include "SRHandler.h"
#define SHIFTPWM_USE_TIMER2
const int ShiftPWM_latchPin = 8;
const bool ShiftPWM_invertOutputs = false;
const bool ShiftPWM_balanceLoad = false;
#include <ShiftPWM.h>

const byte ledNum = 16; // total number of leds used
unsigned char maxBrightness = 255;
unsigned char pwmFrequency = 75;
unsigned int numRegisters = 2;

unsigned int VuL[] = {0, 1, 2, 3, 4, 5, 6, 7};       // VU Master Left
unsigned int VuR[] = {8, 9, 10, 11, 12, 13, 14, 15}; // VU Master Right

unsigned int red = 180;
unsigned int green = 255;
unsigned int blue = 10;
unsigned int yellow = 100;

SRHandler::SRHandler()
{
    this->ccVuLLastValue = 0;
    this->ccVuRLastValue = 0;
}

void SRHandler::begin()
{
    // Sets the number of 8-bit registers that are used.
    ShiftPWM.SetAmountOfRegisters(numRegisters);

    ShiftPWM.Start(pwmFrequency, maxBrightness);
}

void SRHandler::valueDidChange(byte number, byte value)
{
    int value_ = value;
    if (number == 12)
    {
        if (value_ != ccVuLLastValue)
        {
            setRegister(value_, VuL);
            this->ccVuLLastValue = value;
        }
    }
    if (number == 13)
    {
        if (value_ != ccVuRLastValue)
        {
            setRegister(value_, VuR);
            this->ccVuRLastValue = value;
        }
    }
}

void SRHandler::setRegister(int val, unsigned int pinSet[])
{
    switch (val)
    {
    case 0:
        for (int i = 0; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        break;
    case 1:
        for (int i = 1; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        ShiftPWM.SetOne(pinSet[0], green);
        break;
    case 2:
        for (int i = 2; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        for (int i = 0; i < 2; i++)
        {
            ShiftPWM.SetOne(pinSet[i], green);
        }
        break;
    case 3:
        for (int i = 3; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        for (int i = 0; i < 3; i++)
        {
            ShiftPWM.SetOne(pinSet[i], green);
        }
        break;
    case 4:
        for (int i = 4; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        for (int i = 0; i < 4; i++)
        {
            ShiftPWM.SetOne(pinSet[i], green);
        }
        break;
    case 5:
        for (int i = 5; i < 7; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        for (int i = 0; i < 5; i++)
        {
            ShiftPWM.SetOne(pinSet[i], green);
        }
        break;
    case 6:
        for (int i = 6; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        for (int i = 0; i < 5; i++)
        {
            ShiftPWM.SetOne(pinSet[i], green);
        }
        ShiftPWM.SetOne(pinSet[5], yellow);
        break;
    case 7:
        for (int i = 7; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        for (int i = 0; i < 6; i++)
        {
            ShiftPWM.SetOne(pinSet[i], green);
        }
        ShiftPWM.SetOne(pinSet[6], yellow);
        break;
    case 8:
        for (int i = 7; i < 8; i++)
        {
            ShiftPWM.SetOne(pinSet[i], LOW);
        }
        for (int i = 0; i < 6; i++)
        {
            ShiftPWM.SetOne(pinSet[i], green);
        }
        ShiftPWM.SetOne(pinSet[6], yellow);
        ShiftPWM.SetOne(pinSet[7], red);
        break;
    }
}
