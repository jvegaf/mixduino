#include "HWBtn.h"

HWBtn::HWBtn(uint8_t ardPin)
{
    _arduinoPin = ardPin;
}

void HWBtn::begin()
{
    pinMode(_arduinoPin, INPUT_PULLUP);
}

BtnState HWBtn::read()
{
    _cState = digitalRead(_arduinoPin);

    if ((millis() - _lastdebouncetime) > _debouncedelay)
        {
            if (_pState != _cState)
            {
                lastdebouncetime = millis();
                _pState = _cState;
                if (_cState == LOW)
                {
                    return BtnState::TURN_OFF;
                }
                else
                {
                    return BtnState::TURN_ON;
                }
            }
            return BtnState::SAME;
        }
}
