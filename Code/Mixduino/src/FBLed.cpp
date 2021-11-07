#include "FBLed.h"  


FBLed::FBLed(Shifter* shf, uint8_t outPos)
	: OutputBase(outPos)
{
	_shft = shf;
}

void FBLed::setTo(uint8_t value) {
	_shft->setPin(_outPos, value);
    _shft->write();
}
