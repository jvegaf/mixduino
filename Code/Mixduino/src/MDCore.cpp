#include "MDCore.h"

byte ccOUT[] = {MASTER_OUT_R, MASTER_OUT_L, LEVEL_DECK_C, LEVEL_DECK_B, LEVEL_DECK_A};
byte vuValues[] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
byte vuRegs[] = {0, 0, 0, 0, 0};
uint16_t fbRegs = 0;
byte noteSet[] = {0, MONITOR_CUE_C, PLAY_DECK_B, CUE_DECK_B, FX2_BTN_3, FX2_BTN_2, FX2_BTN_1, 0, 0, CUE_DECK_A, PLAY_DECK_A, FX1_BTN_1, FX1_BTN_2, FX1_BTN_3, MONITOR_CUE_A, MONITOR_CUE_B};
byte rgbNoteSet[] = {HOTCUE_1T_DK_A,
                     HOTCUE_2T_DK_A,
                     HOTCUE_3T_DK_A,
                     HOTCUE_4T_DK_A,
                     HOTCUE_5T_DK_A,
                     HOTCUE_6T_DK_A,
                     HOTCUE_7T_DK_A,
                     HOTCUE_8T_DK_A,
                     RANGE_SELECTOR_DK_A,
                     SYNC_ON_DECK_A,
                     HOTCUE_1T_DK_B,
                     HOTCUE_2T_DK_B,
                     HOTCUE_3T_DK_B,
                     HOTCUE_4T_DK_B,
                     HOTCUE_5T_DK_B,
                     HOTCUE_6T_DK_B,
                     HOTCUE_7T_DK_B,
                     HOTCUE_8T_DK_B,
                     RANGE_SELECTOR_DK_B,
                     SYNC_ON_DECK_B};
SRKit vuSR(SF_CLOCK, VU_SF_DATA, VU_LATCH);
SRKit fbSR(SF_CLOCK, FB_SF_DATA, FB_LATCH);
NPKit npixels;

void MDCore::begin()
{
    vuSR.begin();
    fbSR.begin();
    npixels.begin();
}

void MDCore::cChange(byte channel, byte number, byte value)
{
    switch (channel)
    {
    case 1: // neopixels
        rgbOn(number, value);
        break;
    case 2: // fb
        vuChange(number, value);
        break;

    default:
        break;
    }
}

void MDCore::noteOn(byte channel, byte number, byte value)
{
    byte idx = getIdx(noteSet, number);
    uint16_t mask = 1 << idx;
    fbRegs = fbRegs | mask;
    byte resArr[2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);
}

void MDCore::noteOff(byte channel, byte number, byte value)
{
    byte idx = getIdx(noteSet, number);
    uint16_t mask = 1 << idx;
    fbRegs = fbRegs & ~mask;
    byte resArr[2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);
}

void MDCore::vuChange(byte number, byte value)
{
    byte idx = getIdx(ccOUT, number);
    if (vuRegs[idx] == vuValues[value])
    {
        return;
    }
    vuRegs[idx] = vuValues[value];
    vuSR.sendState(vuRegs);
}

void MDCore::rgbOn(byte number, byte value)
{
    npixels.handleON(number, value);
}

void MDCore::rgbOff(byte number, byte value)
{
    byte idx = getIdx(rgbNoteSet, number);
    npixels.handleOFF(idx, value);
}

byte MDCore::getIdx(byte *controlSet, byte num)
{
    for (byte i = 0; i < sizeof(controlSet); i++)
    {
        if (controlSet[i] == num)
        {
            return i;
        }
    }
    return -1;
}