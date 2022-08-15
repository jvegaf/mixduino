#pragma once

#include <Arduino.h>

class Muxer
{
private:
  const uint8_t* mux_pins;
	const uint8_t sig_pin;
	const uint8_t* elements;
	const uint8_t t_elements;
	uint16_t* p_state;
	uint16_t* c_state;

	uint32_t* lastdebouncetime = 0;
	uint32_t debouncedelay{20};
	
	void setMuxChannel(uint8_t channel);

public:
	Muxer(const uint8_t* mux_pins_ptr, const uint8_t sig, const uint8_t* el, const uint8_t t_el)
	: mux_pins(mux_pins_ptr), sig_pin(sig), elements(el), t_elements(t_el)
	{
		p_state = new uint16_t[t_el]();
    c_state = new uint16_t[t_el]();
    lastdebouncetime = new uint32_t[t_el]();
	}
	
	/**
	 *  callback function
	 *  parameter 1: element id
	 *  parameter 2: state
	 */
	void read(void (*func)(uint8_t, State));
};
