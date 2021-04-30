
#ifndef ARDUINO_SRKIT_H
#define ARDUINO_SRKIT_H
#include <Arduino.h>

class SRKit  
{
	private:
		uint8_t* pVUValues;
		uint8_t* pMainValues;
		void clear();
		void shiftOut(uint8_t* myDataOut);
		void shiftAll();
	public:

		SRKit();
		~SRKit();

};
#endif



