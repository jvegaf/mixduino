#include "Input.h"

Input::Input(uint8_t inputIndex)
    : InputBase(inputIndex)
{

}

Input::Input(uint8_t inputIndex, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
	: InputBase(inputIndex)
{
	_funOn = funcOn;
    _funOff = funcOff;
}




