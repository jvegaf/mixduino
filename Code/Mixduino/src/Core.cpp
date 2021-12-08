#include "Core.hpp"

namespace MD
{

void Core::vuChange(uint8_t number, uint8_t value)
{
    _vuSet[number].setLevel(value);
}

void Core::readDecksMode()
{
    _leftFuncMode->read();
    _rightFuncMode->read();
    checkDeckMode(_leftFuncMode, _leftPad);
    checkDeckMode(_rightFuncMode, _rightPad);
}

void Core::checkDeckMode(FuncMode *fm, PadContainer *p)
{
    if (!fm->isDisposed())
    {
        p->setNote(fm->getModeNote());
        p->setTo(fm->getModeColor());
        fm->dispose();
        if (fm->getMode() == deckMode::MODE_HOTCUE)
        {
            sendMonState();
        }
    }
}

void Core::setInitialDeckB() {
	_funcs->setTo(0, 1);
}

void Core::sendMonState() {
	fnOn(SEND_MON_STATE, 127, 3);
	fnOff(SEND_MON_STATE, 127, 3);
}
} // namespace MD

