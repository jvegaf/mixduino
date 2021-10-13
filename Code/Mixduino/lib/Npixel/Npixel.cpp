#include "Npixel.h"  

Npixel::Npixel(uint8_t position, uint8_t value)
{
	_position = position;
    _value = value;
}

uint8_t Npixel::position() const {
	return _position;
}

uint8_t Npixel::value() const {
	return _value;
}
