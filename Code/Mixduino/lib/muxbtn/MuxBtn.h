
#ifndef ARDUINO_MUXBTN_H
#define ARDUINO_MUXBTN_H
#include <Arduino.h>
#include "pin_map.h"

class MuxBtn  
{
	private:
		uint8_t signal;
		uint8_t channel;
		int pState = 0;
		int cState;
		unsigned long lastdebouncetime;
		unsigned long debouncedelay = 20;
		void setMuxChannel(uint8_t channel);

	public:

		MuxBtn(uint8_t sigPin, uint8_t muxCH);
		void begin();
		int read();

};
#endif
