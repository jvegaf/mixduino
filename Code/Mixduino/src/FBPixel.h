
#pragma once
#ifndef FBPIXEL_H
#define FBPIXEL_H

#include <Arduino.h>
#include "OutputBase.h"
#include "NPKit.h"

class FBPixel : public OutputBase
{
	private:
		NPKit* _npkit;

	public:
		FBPixel(NPKit* npkit, uint8_t outPos);
		FBPixel() = default;
		void setTo(uint8_t value);
		

};

#endif // FBPIXEL_H
