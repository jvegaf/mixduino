#include "FBPixel.h"  


FBPixel::FBPixel(NPKit* npkit, uint8_t outPos)
	: OutputBase(outPos)
{
	_npkit = npkit;
}

void FBPixel::setTo(uint8_t value)
{
    _npkit->handleChange(_outPos, value);
}
