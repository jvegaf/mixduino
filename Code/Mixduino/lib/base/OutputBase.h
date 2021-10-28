
#ifndef ARDUINO_OUTPUTBASE_H
#define ARDUINO_OUTPUTBASE_H
#include <Arduino.h>

class OutputBase  
{
	public:
		virtual void setTo(uint32_t state);

};
#endif
