#include "MDCore.h"

uint8_t ccOUT[] = {MASTER_OUT_R, MASTER_OUT_L, LEVEL_DECK_C, LEVEL_DECK_B, LEVEL_DECK_A};
uint8_t vuValues[] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
uint8_t vuRegs[] = {0, 0, 0, 0, 0};
uint16_t fbRegs = 0;
uint8_t noteSet[] = {0, MONITOR_CUE_C, PLAY_DECK_B, CUE_DECK_B, FX2_BTN_3, FX2_BTN_2, FX2_BTN_1, 0, 0, CUE_DECK_A, PLAY_DECK_A, FX1_BTN_1, FX1_BTN_2, FX1_BTN_3, MONITOR_CUE_A, MONITOR_CUE_B};
// TODO: create array of np notes
SRKit vuSR(SF_CLOCK, VU_SF_DATA, VU_LATCH);
SRKit fbSR(SF_CLOCK, FB_SF_DATA, FB_LATCH);
NPKit leftNP(NP_SIG_LEFT, 10);
NPKit rightNP(NP_SIG_RIGHT, 10);

void MDCore::begin()
{
    vuSR.begin();
    fbSR.begin();
}

void MDCore::cChange(uint8_t number, uint8_t value)
{
    uint8_t idx = getIdx(ccOUT, number);
    if (vuRegs[idx] == vuValues[value]){ return; }
    vuRegs[idx] = vuValues[value];
    vuSR.sendState(vuRegs);
}

void MDCore::noteOn(uint8_t channel, uint8_t number, uint8_t value)
{
    switch (channel)
    {
    case 1: // neopixels
        
        break;
    case 2: // fb
        fbOn(number, value);
        break;
    
    default:
        break;
    }
}

void MDCore::fbOn(uint8_t number, uint8_t value)
{
    uint8_t idx = getIdx(noteSet, number);
    uint16_t mask = 1 << idx;
    fbRegs = fbRegs | mask ;
    uint8_t resArr [2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);

}

void MDCore::noteOff(uint8_t number, uint8_t value)
{
    uint8_t idx = getIdx(noteSet, number);
    uint16_t mask = 1 << idx;
    fbRegs = fbRegs & ~mask ;
    uint8_t resArr [2];
    resArr[0] = fbRegs;
    resArr[1] = fbRegs >> 8;
    fbSR.sendState(resArr);
}

uint8_t MDCore::getIdx(uint8_t *controlSet, uint8_t controlNum)
{
    for (uint8_t i = 0; i < sizeof(controlSet); i++)
    {
        if (controlSet[i] == controlNum)
        {
            return i;
        }
    }
}

uint8_t MDCore::getIdx(uint16_t *controlSet, uint8_t controlNum)
{
    for (uint8_t i = 0; i < sizeof(controlSet); i++)
    {
        if (controlSet[i] == controlNum)
        {
            return i;
        }
    }
}
