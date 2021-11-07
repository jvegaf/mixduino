#include "MuxInput.h"

MuxInput::MuxInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex)
    : Input(inputIndex)
{
    _mxPins = mxPins;
    _mxSigPin = sig;
}

MuxInput::MuxInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
    : Input(inputIndex, funcOn, funcOff)
{
    _mxPins = mxPins;
    _mxSigPin = sig;
}

void MuxInput::read(uint8_t midiCh, uint8_t note)
{
    setMuxChannel(_inPos);
    _cState = digitalRead(_mxSigPin);
    if ((millis() - _lastdebouncetime) > DEBOUNCE_DELAY)
    {
        if (_pState != _cState)
        {
            _lastdebouncetime = millis();

            if (_cState == LOW)
            {
                funOn(note, 127, midiCh);
            }
            else
            {
                funOff(note, 127, midiCh);
            }

            _pState = _cState;
        }
    }
}

void MuxInput::setMuxChannel(uint8_t channel)
{
    digitalWrite(_mxPins[0], bitRead(channel, 0));
    digitalWrite(_mxPins[1], bitRead(channel, 1));
    digitalWrite(_mxPins[2], bitRead(channel, 2));
    digitalWrite(_mxPins[3], bitRead(channel, 3));
}
