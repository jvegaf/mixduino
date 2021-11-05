
#pragma once
#ifndef INPUT_BASE_H
#define INPUT_BASE_H
#include <Arduino.h>
#include "md_defs.h"

class InputBase  
{
	public:
		virtual void begin(void (*funcOn)(uint8_t,uint8_t,uint8_t), void (*funcOff)(uint8_t,uint8_t,uint8_t), uint8_t midCh) = 0;
		virtual void read(uint8_t input_pos, uint8_t noteIndex) = 0;
};

#endif // INPUT_BASE_H
