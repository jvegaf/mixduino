#include "MDCore.h"

byte vuValues[] = {
    B00000000,
    B00000001,
    B00000011,
    B00000111,
    B00001111,
    B00011111,
    B00111111,
    B01111111,
    B11111111,
};
byte regsVU[] = { 0, 0, 0, 0, 0 };
uint16_t fbRegs = 0;
byte noteSet[] = {0, MONITOR_CUE_C, PLAY_DECK_B, CUE_DECK_B, FX2_BTN_3, FX2_BTN_2, FX2_BTN_1, 0, 0, CUE_DECK_A, PLAY_DECK_A, FX1_BTN_1, FX1_BTN_2, FX1_BTN_3, MONITOR_CUE_A, MONITOR_CUE_B};
byte nSetAmount = 16U;
SRKit vuSR(SF_CLOCK, VU_SF_DATA, VU_LATCH, 5);
SRKit fbSR(SF_CLOCK, FB_SF_DATA, FB_LATCH, 2);
NPKit npL(NP_SIG_LEFT, 11);
NPKit npR(NP_SIG_RIGHT, 12);

void MDCore::begin()
{
    vuSR.begin();
    fbSR.begin();
    npL.begin();
    npR.begin();
}

void MDCore::cChange(byte channel, byte number, byte value)
{
    switch (channel)
    {
    case 1: // npL
        npChange(Align::LEFT, number, value);
        break;
    case 2: // npR
        npChange(Align::RIGHT, number, value);
        break;
    case 3: // VU
        vuChange(number, value);
        break;

    default:
        break;
    }
}

void MDCore::noteOn(byte channel, byte number, byte value)
{
    uint16_t mask = 1 << number;
    fbRegs = fbRegs | mask;
    byte resArr[2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);
}

void MDCore::noteOff(byte channel, byte number, byte value)
{
    uint16_t mask = 1 << number;
    fbRegs = fbRegs & ~mask;
    byte resArr[2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);
}

void MDCore::vuChange(byte position, byte value)
{
        regsVU[position] = vuValues[value];
        vuSR.sendState(regsVU);
}

void MDCore::npChange(Align al, byte position, byte value)
{
    Npixel pix(position, value);
    if (al == Align::LEFT)
    {
        npL.handleChange(pix);
        return;
    }
    npR.handleChange(pix);
}