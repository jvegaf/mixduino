#include "ModeInput.h"

ModeInput::ModeInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex)
    : MuxInput(mxPins, sig, inputIndex)
{
}

boolean ModeInput::read()
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
                return true;
            }

            _pState = _cState;
        }
        return false;
    }
}
