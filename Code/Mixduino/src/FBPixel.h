
#pragma once
#ifndef FBPIXEL_H
#define FBPIXEL_H

#include <Arduino.h>
#include "Output.h"
#include "..\lib\npkit\NPKit.h"

class FBPixel : public Output
{
	private:
		NPKit* _npkit;

	public:
		FBPixel(NPKit* npkit, uint8_t outPos)
		{
			_npkit = npkit;
		}
		FBPixel() = default;

		void setTo(uint8_t value) override
		{
		    _npkit->handleChange(_outPos, value);
		}
		

};

#endif // FBPIXEL_H
