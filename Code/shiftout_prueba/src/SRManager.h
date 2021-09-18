
#ifndef ARDUINO_SRMANAGER_H
#define ARDUINO_SRMANAGER_H
#include <Arduino.h>

class SRManager  
{
	private:
		
	public:

		SRManager(); // int[] with cc number assigments
		void begin();
		void setLevel(uint8_t level);
};
#endif
