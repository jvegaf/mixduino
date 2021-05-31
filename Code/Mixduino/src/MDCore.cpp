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
byte regsVU[] = {0, 0, 0, 0, 0};
int fbRegs = 0;
byte noteSet[] = {0, MONITOR_CUE_C, PLAY_DECK_B, CUE_DECK_B, FX2_BTN_3, FX2_BTN_2, FX2_BTN_1, 0, 0, CUE_DECK_A, PLAY_DECK_A, FX1_BTN_1, FX1_BTN_2, FX1_BTN_3, MONITOR_CUE_A, MONITOR_CUE_B};
byte nSetAmount = 16;
SRKit vuSR(SF_CLOCK, VU_SF_DATA, VU_LATCH, 5);
Shifter fbackSR(FB_SF_DATA, FB_LATCH, SF_CLOCK, 2);
byte npRMap[] = {
    NP_PADR_8,
    NP_PADR_7,
    NP_PADR_6,
    NP_PADR_5,
    NP_PADR_4,
    NP_PADR_3,
    NP_PADR_2,
    NP_PADR_1,
    NP_DECK_SEL,
    NP_RANGE_R,
    NP_SYNC_R,
};
int npRAmount = 11;
NPKit npL(NP_SIG_LEFT, 10);
NPKit npR(NP_SIG_RIGHT, npRAmount);

void MDCore::begin()
{
    vuSR.begin();
    npL.begin();
    npR.begin();
    setInitialDeckB();
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
    for (int i = 0; i < nSetAmount; i++)
    {
        if (noteSet[i] != number)
        {
            continue;
        }
        fbackSR.setPin(i, HIGH);
        fbackSR.write();
    }
}

void MDCore::noteOff(byte channel, byte number, byte value)
{
    for (int i = 0; i < nSetAmount; i++)
    {
        if (noteSet[i] != number)
        {
            continue;
        }
        fbackSR.setPin(i, LOW);
        fbackSR.write();
    }
}

void MDCore::vuChange(byte number, byte value)
{
    if (regsVU[number] != vuValues[value])
    {
        regsVU[number] = vuValues[value];
        vuSR.sendState(regsVU);
    }
}

void MDCore::npChange(Align al, byte position, byte value)
{
    if (al == Align::LEFT)
    {
        Npixel pix(position, value);
        npL.handleChange(pix);
        return;
    }
    for (int i = 0; i < npRAmount; i++)
    {
        if (npRMap[i] != position)
        {
            continue;
        }
        Npixel pix(i, value);
        npR.handleChange(pix);
    }
}

void MDCore::setInitialDeckB()
{
    Npixel pix(NP_DECK_SEL, 1);
    npR.handleChange(pix);
}
