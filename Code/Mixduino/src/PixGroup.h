
#ifndef ARDUINO_PIXGROUP_H
#define ARDUINO_PIXGROUP_H
#include <Arduino.h>
#include "NPKit.h"

class PixGroup  
{
	private:
		const uint8_t* _pxAggr;
		uint8_t _tPixls;
		NPKit* _npk;

	public:
		PixGroup(const uint8_t* pxSet, uint8_t tPixels, NPKit* npkit);
		void setPixel(uint8_t index, uint8_t valueColor);
		void setAll(uint8_t valueColor);

};
#endif
