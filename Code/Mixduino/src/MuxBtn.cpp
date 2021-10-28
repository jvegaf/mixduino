#include "MuxBtn.h"

void MuxBtn::setMuxChannel(uint8_t channel)
{
    digitalWrite(muxPins[0], bitRead(channel, 0));
    digitalWrite(muxPins[1], bitRead(channel, 1));
    digitalWrite(muxPins[2], bitRead(channel, 2));
    digitalWrite(muxPins[3], bitRead(channel, 3));
}

MuxBtn::MuxBtn(uint8_t sigPin, uint8_t muxCH)
{
    signal = sigPin;
    channel = muxCH;
}

void MuxBtn::begin()
{
    pinMode(signal, INPUT_PULLUP);
    pinMode(muxPins[0], OUTPUT);
    pinMode(muxPins[1], OUTPUT);
    pinMode(muxPins[2], OUTPUT);
    pinMode(muxPins[3], OUTPUT);
}

MDState MuxBtn::read()
{
    setMuxChannel(channel);

        _cState = digitalRead(signal);
        if ((millis() - _lastdebouncetime) > _debouncedelay)
        {
            if (_pState != _cState)
            {
                _lastdebouncetime = millis();
                _pState = _cState;
                if (_cState == LOW)
                {
                    return MDState::TURN_OFF;
                }
                else
                {
                    return MDState::TURN_ON;
                }
            }
            return MDState::SAME;
        }
}
