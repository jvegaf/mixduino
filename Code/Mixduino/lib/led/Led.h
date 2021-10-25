
#ifndef ARDUINO_LED_H
#define ARDUINO_LED_H
#include <Arduino.h>
#include <Shifter.h>

class Led  
{
	private:
		Shifter* reg;
		uint8_t pos;

	public:
		Led(Shifter register, uint8_t position);
		void setTo(int state);
};
#endif
