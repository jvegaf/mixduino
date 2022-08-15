#pragma once

#include <Arduino.h>
#include "md_enums.hpp"


class BtnKit
{
private:
	uint8_t const *pins;
	uint8_t const *elements;
	const uint8_t total_pins;
	uint16_t *pState;
	uint16_t *cState;

	uint32_t* lastdebouncetime;
	uint32_t debouncedelay = 20;
public:
	BtnKit(const uint8_t* ard_pins, const uint8_t* el, const uint8_t t_pins); 
	void read(void (*func)(uint8_t, State));
};
