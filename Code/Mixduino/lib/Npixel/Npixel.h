
#ifndef ARDUINO_NPIXEL_H
#define ARDUINO_NPIXEL_H
#include <Arduino.h>
class Npixel  
{
	private:
		uint8_t _position;
		uint8_t _value;
	public:
		Npixel(uint8_t position, uint8_t value);
		uint8_t position() const;
		uint8_t value() const;
};
#endif
