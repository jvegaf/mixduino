#include "PixGroup.h"  

PixGroup::PixGroup(const uint8_t* pxSet, uint8_t tPixels, NPKit* npkit)
{
	_pxAggr = pxSet;
    _tPixls = tPixels;
    _npk = npkit;
}

void PixGroup::setPixel(uint8_t index, uint8_t valueColor) {
	_npk->handleChange(_pxAggr[index], valueColor);
}

void PixGroup::setAll(uint8_t valueColor) {
	for (uint8_t i = 0; i < _tPixls; i++)
    {
        _npk->handleChange(_pxAggr[i], valueColor);
    }
    
}
