#include "MDCore.h"

uint8_t const T_NP_PAD = 8;

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

MDCore::MDCore()
{
    _npkit = new NPKit(NP_DATA, T_NP);
    _pgLeftPad = new PixGroup(PIXLS_PAD_L, T_NP_PAD, _npkit);
    _pgRightPad = new PixGroup(PIXLS_PAD_R, T_NP_PAD, _npkit);
    _deckLeftMode = new MDMode(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWMODE_L);
    _deckRightMode = new MDMode(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWMODE_R);
    _leftPadBtns = new MuxerPad(MUXPIN_BUNDLE, LEFT_SWMUX_SIG);
    _rightPadBtns = new MuxerPad(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG);
    _leftBtns = new Muxer(MUXPIN_BUNDLE, LEFT_SWMUX_SIG);
    _rightBtns = new Muxer(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG);
}

void MDCore::begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    fnon = funcOn;
    fnoff = funcOff;
    _deckLeftMode->begin();
    _deckRightMode->begin();
    _leftBtns->begin(MUX_SW_BUNDLE_L, T_MUX_SW_L, LEFT_BTNS_CH);
    _rightBtns->begin(MUX_SW_BUNDLE_R, T_MUX_SW_R, RIGHT_BTNS_CH);
    _leftPadBtns->begin(SW_PADL_BUNDLE, T_DECK_PADS, LEFT_PAD_CH);
    _rightPadBtns->begin(SW_PADR_BUNDLE, T_DECK_PADS, RIGHT_PAD_CH);
    btns.begin(ARDUINO_BTNS_CH);
    for (uint8_t i = 0; i < t_VUSet; i++)
    {
        vuSet[i].begin();
    }
    _npkit->begin();
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
    _leftPadBtns->setNoteNum(_deckLeftMode->getModeNote());
    _rightPadBtns->setNoteNum(_deckRightMode->getModeNote());
    _leftPadBtns->read(fnon, fnoff);
    _rightPadBtns->read(fnon, fnoff);
    _leftBtns->read(fnon, fnoff);
    _rightBtns->read(fnon, fnoff);
    btns.read(fnon, fnoff);
}

void MDCore::vuChange(uint8_t number, uint8_t value)
{
    vuSet[number].setLevel(value);
}

void MDCore::npChange(uint8_t position, uint8_t value)
{
    _npkit->handleChange(position, value);
}

void MDCore::setInitialDeckB()
{
    this->npChange(NP_DECK_SEL, 1);
}

void MDCore::readDecksMode()
{
    _deckLeftMode->read();
    checkDeckMode(Align::LEFT);
    _deckRightMode->read();
    checkDeckMode(Align::RIGHT);
}

void MDCore::checkDeckMode(Align al)
{

    switch (al)
    {
    case Align::LEFT:
        _npkit->handleChange(NP_MODE_L, _deckLeftMode->getModeColor());
        _pgLeftPad->setAll(_deckLeftMode->getModeColor());
        break;

    case Align::RIGHT:
        _npkit->handleChange(NP_MODE_R, _deckRightMode->getModeColor());
        _pgRightPad->setAll(_deckRightMode->getModeColor());
        break;

    default:
        break;
    }
}
