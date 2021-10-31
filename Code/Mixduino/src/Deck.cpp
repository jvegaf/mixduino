#include "Deck.h"

void Deck:: readPadMode()
{
    MDState::StateType cState = this->modeFunc->read();
    if (cState == MDState::StateType::TURN_ON)
    {
        MDMode::ModeType nextMode = incrementMode(this->_deckMode);
        this->padp->updateMode(nextMode);
        this->_deckMode = nextMode;
    }
}

MDMode::ModeType Deck::incrementMode(MDMode::ModeType pMode) 
{
    switch (pMode)
    {
    case   MDMode:: ModeType:: HOTCUE: 
    return MDMode:: ModeType:: LOOP;

    case   MDMode:: ModeType:: LOOP: 
    return MDMode:: ModeType:: FX;

    case   MDMode:: ModeType:: FX: 
    return MDMode:: ModeType:: HOTCUE;
    
           default: 
    return MDMode:: ModeType:: HOTCUE;
    }
}

