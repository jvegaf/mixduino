#include "Feedback.h"  

Feedback::Feedback(Shifter* shft, const uint8_t* group, const uint8_t count)
{
	_shftr = shft;
    _fbAggr = group;
    _totalLeds = count;
}

void Feedback::setTo(uint8_t index, boolean value) {
	_shftr->setPin(_fbAggr[index], value);
    _shftr->write();
}
