
#ifndef ARDUINO_LED_H
#define ARDUINO_LED_H
#include <OutputBase.h>
#include <Arduino.h>
#include <Shifter.h>

class Led : public OutputBase
{
	private:
		Shifter *_reg;
		uint8_t _pos;

	public:
		Led(Shifter shifter, uint8_t position);
		void setTo(uint32_t state);
};
#endif
