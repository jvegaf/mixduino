
#pragma once
#ifndef OUT_DTO_H
#define OUT_DTO_H

#include <Arduino.h>

struct OutDTO
{
	uint8_t position;
	boolean state;
	uint8_t color;
};

#endif // OUT_DTO_H
