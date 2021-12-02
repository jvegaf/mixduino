
#pragma once
#include "npixel.hpp"
#include "vumeter.hpp"
#include "np_map.h"
#include "pin_map.h"
#include "sr_fb_map.h"
#include <Align.h>
#include <Arduino.h>
#include <Shifter.h>

namespace mdcore
{

	class Core
	{
	public:
		void begin();
		void cChange(uint8_t channel, uint8_t number, uint8_t value);
		void noteOn(uint8_t channel, uint8_t number, uint8_t value);
		void noteOff(uint8_t channel, uint8_t number, uint8_t value);

	private:
		void vuChange(uint8_t number, uint8_t value);
		void npChange(uint8_t position, uint8_t value);
		void setInitialDeckB();
	};
} // namespace mdcore
