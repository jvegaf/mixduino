#include "Deck.h"

Deck::Deck(DeckAggregate aggr)
{
    modeFunc = aggr.modeFunc;
    dFuncs = aggr.deckFuncs;
}

void Deck::begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t), Adafruit_NeoPixel *aNP)
{
    funcNoteOn = funcOn;
    funcNoteOff = funcOff;

    modeFunc->in->begin();
    static_cast<Npixel *>(modeFunc->out)->setNPObject(aNP);

    for (uint8_t i = 0; i < T_DECK_FUNCS; i++)
    {
        dFuncs[i].in->begin();
    }

    for (uint8_t i = 0; i < T_DECK_FUNCS_RGB; i++)
    {
        static_cast<Npixel *>(dFuncs[i].out)->setNPObject(aNP);
    }
}

void Deck::read()
{
}

void Deck::onNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
}

void Deck::onNoteOff(uint8_t channel, uint8_t number, uint8_t value)
{
}

void Deck::readPadMode()
{
    MDState cState = modeFunc->in->read();
    if (cState == MDState::TURN_ON)
    {
        Mode nextMode = incrementMode(this->deckMode);
        this->deckMode = nextMode;
    }
}

Mode Deck::incrementMode(Mode pMode) {
	switch (pMode)
    {
    case Mode::HOTCUE :
        return Mode::LOOP;

    case Mode::LOOP :
        return Mode::FX;

    case Mode::FX :
        return Mode::HOTCUE;
    
    default:
        break;
    }    
}
