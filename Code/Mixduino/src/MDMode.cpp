#include "MDMode.h"

void MDMode::setMuxChannel(uint8_t channel)
{
    digitalWrite(_mxPins[0], bitRead(channel, 0));
    digitalWrite(_mxPins[1], bitRead(channel, 1));
    digitalWrite(_mxPins[2], bitRead(channel, 2));
    digitalWrite(_mxPins[3], bitRead(channel, 3));
}

void MDMode::incrementMode() {
	switch (_dMode)
    {
    case deckMode::HOTCUE_MODE :
        _dMode = LOOP_MODE;
        _dmColor = LOOP_MODE_COLOR;
        break;

    case deckMode::LOOP_MODE:
        _dMode = FX_MODE;
        _dmColor = FX_MODE_COLOR;
        break;

    case deckMode::FX_MODE:
        _dMode = HOTCUE_MODE;
        _dmColor = HOTCUE_MODE_COLOR;
        break;

    default:
        break;
    }
}


MDMode::MDMode(const uint8_t *mxPins, uint8_t sig, uint8_t position)
{
    _mxPins = mxPins;
    _mxSigPin = sig;
    _position = position;
    _pState = 0;
    _cState = 0;
}

void MDMode::begin()
{
    _dMode = deckMode::HOTCUE_MODE;
    _dmColor = deckModeColor::HOTCUE_MODE_COLOR;
    _pState = LOW;
}


void MDMode::read()
{
    setMuxChannel(_position);
    _cState = digitalRead(_mxSigPin);
    if ((millis() - _lastdebouncetime) > debouncedelay)
        {
            if (_pState != _cState)
            {
                _lastdebouncetime = millis();

                if (_cState == LOW)
                {
                    incrementMode();
                }

                _pState = _cState;
            }
        }
}

uint8_t MDMode::getMode() {
	return _dMode;
}

uint8_t MDMode::getModeColor() {
	return _dmColor;
}
