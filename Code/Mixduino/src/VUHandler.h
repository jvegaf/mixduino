
#ifndef ARDUINO_VUHANDLER_H
#define ARDUINO_VUHANDLER_H
#define SHIFTPWM_USE_TIMER2
const int ShiftPWM_latchPin = 8;
#include <Arduino.h>
#include <ShiftPWM.h> 

class VUHandler  
{
	private:
		int ccVuMRLastValue;
		int ccVuMLLastValue;
		unsigned char maxBrightness;
		unsigned char pwmFrequency;
		unsigned int numRegisters;
		

	public:

		VUHandler();
		~VUHandler();

};
#endif
