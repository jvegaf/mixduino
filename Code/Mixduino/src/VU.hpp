#pragma once

#include <Arduino.h>

namespace MD
{
	
class VU  
{
	private:
		uint8_t data_pin;
		uint8_t latch_pin;
		uint8_t clock_pin;
		void clear();
	public:
		VU(uint8_t p_data, uint8_t p_latch, uint8_t p_clock);
		VU() = default;
		void begin();
		void setLevel(uint8_t level);

};
} // namespace MD
