#pragma once

#include <Arduino.h>

class Mux
{
private:
	const uint8_t* muxpins;
	const uint8_t muxSIG;
	const uint8_t position;
	const uint8_t element_id;
	uint16_t pState{0};
	uint16_t cState{0};

	unsigned long lastdebouncetime{0};
	unsigned long debouncedelay{20};
	
	void setMuxChannel(uint8_t channel);

public:
	Mux(const uint8_t* m_pins, const uint8_t sig, const uint8_t pos, const uint8_t id);

	/**
	 *  callback function
	 *  parameter 1: element id
	 *  parameter 2: state
	 */
	void read(void (*func)(uint8_t, State));
};
