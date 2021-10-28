#include "HWBtn.h"

HWBtn::HWBtn(uint8_t ardPin)
{
    _arduinoPin = ardPin;
}

void HWBtn::begin()
{
    pinMode(_arduinoPin, INPUT_PULLUP);
}

MDState HWBtn::read()
{
    _cState = digitalRead(_arduinoPin);

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
    }
    return MDState::SAME;
}
