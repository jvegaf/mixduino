
#ifndef ARDUINO_VUMETER_H
#define ARDUINO_VUMETER_H
#include <Arduino.h>

class VUmeter  
{
	private:
		uint8_t data_pin;
		uint8_t latch_pin;
		uint8_t clock_pin;
		void clear();
	public:
		VUmeter(uint8_t p_data, uint8_t p_latch, uint8_t p_clock);
		void begin();
		void setLevel(uint8_t level);

};
#endif
