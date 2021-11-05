
#ifndef ARDUINO_FEEDBACK_H
#define ARDUINO_FEEDBACK_H
#include <Arduino.h>
#include <Shifter.h>

class Feedback  
{
	public:
		Feedback(Shifter* shft, const uint8_t* group, const uint8_t count);
		void setTo(uint8_t index, boolean value);
	private:
		Shifter* _shftr;
		const uint8_t* _fbAggr;
		uint8_t _totalLeds;

};
#endif
