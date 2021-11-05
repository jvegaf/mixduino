#include "MDMode.h"

void MDMode::setMuxChannel(uint8_t channel)
{
    digitalWrite(_mxPins[0], bitRead(channel, 0));
    digitalWrite(_mxPins[1], bitRead(channel, 1));
    digitalWrite(_mxPins[2], bitRead(channel, 2));
    digitalWrite(_mxPins[3], bitRead(channel, 3));
}

void MDMode::incrementMode()
{
    switch (_dMode)
    {
    case deckMode::HOTCUE_MODE:
        _dMode = deckMode::LOOP_MODE;
        _modeColor = LOOP_MODE_COLOR;
        _modeNote = 8;
        break;

    case deckMode::LOOP_MODE:
        _dMode = deckMode::FX_MODE;
        _modeColor = FX_MODE_COLOR;
        _modeNote = 16;
        break;

    case deckMode::FX_MODE:
        _dMode = deckMode::HOTCUE_MODE;
        _modeColor = HOTCUE_MODE_COLOR;
        _modeNote = 0;
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
    _modeColor = HOTCUE_MODE_COLOR;
    _modeNote = 0;
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

uint8_t MDMode::getModeColor() {
	return _modeColor;
}

uint8_t MDMode::getModeNote() {
    return _modeNote;
}

deckMode MDMode::getMode()
{
    return _dMode;
}
