#include "MDCore.h"

byte ccOUT[] = {MASTER_OUT_R, MASTER_OUT_L, LEVEL_DECK_C, LEVEL_DECK_B, LEVEL_DECK_A};
byte nCCOUT = 5;
byte vuValues[] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
byte vuRegs[] = {0, 0, 0, 0, 0};
uint16_t fbRegs = 0;
byte noteSet[] = {0, MONITOR_CUE_C, PLAY_DECK_B, CUE_DECK_B, FX2_BTN_3, FX2_BTN_2, FX2_BTN_1, 0, 0, CUE_DECK_A, PLAY_DECK_A, FX1_BTN_1, FX1_BTN_2, FX1_BTN_3, MONITOR_CUE_A, MONITOR_CUE_B};
byte nSetAmount = 16U;
SRKit vuSR(SF_CLOCK, VU_SF_DATA, VU_LATCH);
SRKit fbSR(SF_CLOCK, FB_SF_DATA, FB_LATCH);
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
        npChange( Align::LEFT, number, value);
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
    byte idx = getIdx(noteSet, nSetAmount, number);
    uint16_t mask = 1 << idx;
    fbRegs = fbRegs | mask;
    byte resArr[2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);
}

void MDCore::noteOff(byte channel, byte number, byte value)
{
    byte idx = getIdx(noteSet, nSetAmount, number);
    uint16_t mask = 1 << idx;
    fbRegs = fbRegs & ~mask;
    byte resArr[2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);
}

void MDCore::vuChange(byte number, byte value)
{
    byte idx = getIdx(ccOUT, nCCOUT, number);
    if (vuRegs[idx] == vuValues[value])
    {
        return;
    }
    vuRegs[idx] = vuValues[value];
    vuSR.sendState(vuRegs);
}

void MDCore::npChange(Align al, byte position, byte value)
{
    Npixel pix(position, value);
    if(al == Align::LEFT){
        npL.handleChange(pix);
        return;
    }
    npR.handleChange(pix);
}

byte MDCore::getIdx(byte* controlSet, byte nCSets, byte num)
{
    for (byte i = 0; i < nCSets; i++)
    {
        if (controlSet[i] == num)
        {
            return i;
        }
    }
}