#include "MDCore.h"


byte regsVU[] = {0, 0, 0, 0, 0};
int fbRegs = 0;
byte noteSet[] = {0, MONITOR_CUE_C, PLAY_DECK_B, CUE_DECK_B, FX2_BTN_3, FX2_BTN_2, FX2_BTN_1, 0, 0, CUE_DECK_A, PLAY_DECK_A, FX1_BTN_1, FX1_BTN_2, FX1_BTN_3, MONITOR_CUE_A, MONITOR_CUE_B};
byte nSetAmount = 16;
SRKit vuSR(SF_CLOCK, VU_SF_DATA, VU_LATCH, 5);
Shifter fbackSR(FB_SF_DATA, FB_LATCH, SF_CLOCK, 2);
NPKit npLPads(NP_L_PADS_DATA, 8);
NPKit npLFB(NP_L_FB_DATA, 2);
NPKit npRPads(NP_R_PADS_DATA, 8);
NPKit npRFB(NP_R_FB_DATA, 3);

void MDCore::begin()
{
    vuSR.begin();
    npLPads.begin();
    npLFB.begin();
    npRPads.begin();
    npRFB.begin();
    setInitialDeckB();
}

void MDCore::cChange(byte channel, byte number, byte value)
{
    switch (channel)
    {
    case 1: // VU
        vuChange(number, value);
        break;
    case 2: // npLPADS
        npPadChange(Align::LEFT, number, value);
        break;
    case 3: // npRPADS
        npPadChange(Align::RIGHT, number, value);
        break;
    case 4: // npLFB
        npFBChange(Align::LEFT, number, value);
        break;
    case 5: // npRFB
        npFBChange(Align::RIGHT, number, value);
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

void MDCore::npPadChange(Align al, byte position, byte value)
{
    Npixel pix(position, value);
    switch (al)
    {
    case Align::LEFT:
        npLPads.handleChange(pix);
        break;

    case Align::RIGHT:
        npRPads.handleChange(pix);
        break;

    default:
        break;
    }
}

void MDCore::npFBChange(Align al, byte position, byte value)
{
    Npixel pix(position, value);
    switch (al)
    {
    case Align::LEFT:
        npLFB.handleChange(pix);
        break;

    case Align::RIGHT:
        npRFB.handleChange(pix);
        break;

    default:
        break;
    }
}

void MDCore::setInitialDeckB()
{
    Npixel pix(NP_DECK_SEL, 1);
    npRPads.handleChange(pix);
}
