
#ifndef ARDUINO_OUTPUTBASE_H
#define ARDUINO_OUTPUTBASE_H
#include <Arduino.h>

class OutputBase  
{
	public:
		virtual void clearAll() = 0;
		void setTo(uint8_t pos, int value) const;

};
#endif
