#include "MDCore.h"

VUmeter vuSet[] = {
    VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK),
    VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK),
    VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK),
    VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK),
    VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK)};

uint8_t t_VUSet = 5;

MDCore::MDCore()
{
    _npkit = new NPKit(NP_DATA, T_NP);
}

void MDCore::begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    fnon = funcOn;
    fnoff = funcOff;
    _npkit->begin();
}

void MDCore::onCChange(uint8_t channel, uint8_t number, uint8_t value)
{
    switch (channel)
    {
    case VUMETERS_CH: // VU
        vuChange(number, value);
        break;

    default:
        break;
    }
}

void MDCore::onNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
    switch (channel)
    {

    case IN_OUT_CH:
        _funcs[number].setTo(value);
        break;

    case LEFT_PAD_CH:
        handlePadNoteChange(State::STATE_ON, _leftFuncMode, _leftPad, number, value);
        break;

    case RIGHT_PAD_CH:
        handlePadNoteChange(State::STATE_ON, _rightFuncMode, _rightPad, number, value);
        break;

    default:
        break;
    }
}

void MDCore::onNoteOff(uint8_t channel, uint8_t number, uint8_t value)
{
    switch (channel)
    {
    case IN_OUT_CH:
        _funcs[number].setTo(LOW); 
        break;

    case LEFT_PAD_CH:
        handlePadNoteChange(State::STATE_OFF, _leftFuncMode, _leftPad, number, value);
        break;

    case RIGHT_PAD_CH:
        handlePadNoteChange(State::STATE_OFF, _rightFuncMode, _rightPad, number, value);
        break;

    default:
        break;
    }
}

void MDCore::readButtons()
{
    readDecksMode();
    _blindFuncs->read();
    _funcs->read();
    _leftPad->read();
    _rightPad->read();
}

void MDCore::vuChange(uint8_t number, uint8_t value)
{
    vuSet[number].setLevel(value);
}

void MDCore::readDecksMode()
{
    _leftFuncMode->read();
    _rightFuncMode->read();
    checkDeckMode(_leftFuncMode, _leftPad);
    checkDeckMode(_rightFuncMode, _rightPad);
}

void MDCore::checkDeckMode(FuncMode *fm, Pad *p)
{
    if (!fm->isDisposed())
    {
        p->setNote(fm->getModeNote());
        p->setTo(fm->getModeColor());
        fm->dispose();
    }
}

void MDCore::handlePadNoteChange(State nState, FuncMode *deckMD, Pad *pad, uint8_t number, uint8_t value)
{
    if (deckMD->getMode() != deckMode::MODE_HOTCUE)
    {
        return;
    }

    if (nState == State::STATE_OFF)
    {
        pad->setTo(number, 0);
        return;
    }

    pad->setTo(number, value);
}
