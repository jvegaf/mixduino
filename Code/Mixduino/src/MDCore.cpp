#include "MDCore.h"

Muxer leftBtns(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A3);
Muxer rightBtns(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);
BtnKit btns(aSwSet, nASw);

VUmeter vuL1 = VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK);
VUmeter vuL2 = VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK);
VUmeter vuL3 = VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK);
VUmeter vuML = VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK);
VUmeter vuMR = VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK);

VUmeter vuSet[] = {vuL1, vuL2, vuL3, vuML, vuMR};

Shifter fbRight(FBR_SIG, FBR_LATCH, SRCLK, 1);
Shifter fbLeft(FBL_SIG, FBL_LATCH, SRCLK, 1);

NPKit npk(NP_DATA, nNP);

void MDCore::begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    fnon = funcOn;
    fnoff = funcOff;
    leftBtns.begin(MUX_SW_BUNDLE_L, T_MUX_SW_L, LEFT_BTNS_CH);
    rightBtns.begin(MUX_SW_BUNDLE_R, T_MUX_SW_R, RIGHT_BTNS_CH);
    btns.begin(ARDUINO_BTNS_CH);
    vuL1.begin();
    vuL2.begin();
    vuL3.begin();
    vuML.begin();
    vuMR.begin();
    npk.begin();
}

void MDCore::onCChange(uint8_t channel, uint8_t number, uint8_t value)
{
    switch (channel)
    {
    case 12: // VU
        vuChange(number, value);
        break;
    case 14: // NPixels
        npChange(number, value);
        break;

    default:
        break;
    }
}

void MDCore::onNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
    for (uint8_t i = 0; i < nFbRight; i++)
    {
        if (fbRightSet[i] == number)
        {
            fbRight.setPin(i, HIGH);
            fbRight.write();
            return;
        }
    }

    for (uint8_t i = 0; i < nFbLeft; i++)
    {
        if (fbLeftSet[i] == number)
        {
            fbLeft.setPin(i, HIGH);
            fbLeft.write();
            return;
        }
    }
}

void MDCore::onNoteOff(uint8_t channel, uint8_t number, uint8_t value)
{
    for (uint8_t i = 0; i < nFbRight; i++)
    {
        if (fbRightSet[i] == number)
        {
            fbRight.setPin(i, LOW);
            fbRight.write();
            return;
        }
    }

    for (uint8_t i = 0; i < nFbLeft; i++)
    {
        if (fbLeftSet[i] == number)
        {
            fbLeft.setPin(i, LOW);
            fbLeft.write();
            return;
        }
    }
}

void MDCore::readButtons()
{
    leftBtns.read(fnon, fnoff);
    rightBtns.read(fnon, fnoff);
    btns.read(fnon, fnoff);
}

void MDCore::vuChange(uint8_t number, uint8_t value)
{
    vuSet[number].setLevel(value);
}

void MDCore::npChange(uint8_t position, uint8_t value)
{
    Npixel pix(position, value);
    npk.handleChange(pix);
}

void MDCore::setInitialDeckB()
{
    this->npChange(NP_DECK_SEL, 1);
}
