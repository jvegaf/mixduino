
#ifndef ARDUINO_MUXBTN_H
#define ARDUINO_MUXBTN_H
#include <Arduino.h>
#include "MDState.h"
#include "InputBase.h"
#include "md_pinmap.h"

class MuxBtn : public InputBase
{
	private:
		uint8_t signal;
		uint8_t channel;
		int _pState = 0;
		int _cState;
		unsigned long _lastdebouncetime;
		unsigned long _debouncedelay = 20;
		void setMuxChannel(uint8_t channel);

	public:
		MuxBtn(uint8_t sigPin, uint8_t muxCH);
		void begin();
		MDState read();

};
#endif
