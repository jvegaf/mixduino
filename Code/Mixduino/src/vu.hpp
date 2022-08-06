
#ifndef ARDUINO_VU_H
#define ARDUINO_VU_H
#include <Arduino.h>

class VU  
{
	public:
		VU(uint8_t p_data, uint8_t p_latch, uint8_t p_clock);
		void begin();
		void setLevel(uint16_t level);

	private:
		uint8_t m_data_pin;
		uint8_t m_latch_pin;
		uint8_t m_clock_pin;
		void clear();

};
#endif
