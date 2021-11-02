#include "MDCore.h"

MDMode deckLeftMode = MDMode(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWMODE_L);
MDMode deckRightMode = MDMode(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWMODE_R);

MuxerPad leftPadBtns(MUXPIN_BUNDLE, LEFT_SWMUX_SIG);
MuxerPad rightPadBtns(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG);
Muxer leftBtns(MUXPIN_BUNDLE, LEFT_SWMUX_SIG);
Muxer rightBtns(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG);

BtnKit btns(ARD_SW_BUNDLE, T_ARD_SW);

VUmeter vuSet[] = {
    VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK),
    VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK),
    VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK),
    VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK),
    VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK)};

uint8_t t_VUSet = 5;

Shifter fbRight(FBR_SIG, FBR_LATCH, SRCLK, 1);
Shifter fbLeft(FBL_SIG, FBL_LATCH, SRCLK, 1);

NPKit npk(NP_DATA, nNP);

void MDCore::begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    fnon = funcOn;
    fnoff = funcOff;
    deckLeftMode.begin();
    deckRightMode.begin();
    leftBtns.begin(MUX_SW_BUNDLE_L, T_MUX_SW_L, LEFT_BTNS_CH);
    rightBtns.begin(MUX_SW_BUNDLE_R, T_MUX_SW_R, RIGHT_BTNS_CH);
    leftPadBtns.begin(SW_PADL_BUNDLE, T_DECK_PADS, LEFT_PAD_CH);
    rightPadBtns.begin(SW_PADR_BUNDLE, T_DECK_PADS, RIGHT_PAD_CH);
    btns.begin(ARDUINO_BTNS_CH);
    for (uint8_t i = 0; i < t_VUSet; i++)
    {
        vuSet[i].begin();
    }
    npk.begin();
    npSetDeckMode(NP_MODE_L, deckLeftMode.getModeColor());
    npSetDeckMode(NP_MODE_R, deckRightMode.getModeColor());
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
    readDecksMode();
    leftPadBtns.setNoteNum(deckLeftMode.getMode());
    rightPadBtns.setNoteNum(deckRightMode.getMode());
    leftPadBtns.read(fnon,fnoff);
    rightPadBtns.read(fnon, fnoff);
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
    npk.handleChange(position, value);
}

void MDCore::setInitialDeckB()
{
    this->npChange(NP_DECK_SEL, 1);
}

void MDCore::readDecksMode() {
    deckLeftMode.read();
    npSetDeckMode(NP_MODE_L, deckLeftMode.getModeColor());
    deckRightMode.read();
    npSetDeckMode(NP_MODE_R, deckRightMode.getModeColor());

}

void MDCore::npSetDeckMode(uint8_t position, uint8_t mode)
{
    npChange(position, mode);
}
