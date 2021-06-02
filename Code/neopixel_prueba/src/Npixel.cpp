#include "Npixel.h"  

Npixel::Npixel(byte position, byte value)
{
	_position = position;
    _value = value;
}

byte Npixel::position() const {
	return _position;
}

byte Npixel::value() const {
	return _value;
}
