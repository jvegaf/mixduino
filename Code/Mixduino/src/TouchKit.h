
#ifndef ARDUINO_TOUCHKIT_H
#define ARDUINO_TOUCHKIT_H
#include <Arduino.h>
#include <Trill.h>

class TouchKit  
{
	private:
	public:
		TouchKit();
		void begin();
		void touchRead(void (*scc_func)(byte, byte, byte));

};
#endif
