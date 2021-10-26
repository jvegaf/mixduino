
#ifndef ARDUINO_MUXBTN_H
#define ARDUINO_MUXBTN_H
#include <Arduino.h>
#include "BtnState.h"
#include "ButtonBase.h"
#include "pin_map.h"

class MuxBtn : public ButtonBase
{
	private:
		uint8_t signal;
		uint8_t channel;
		void setMuxChannel(uint8_t channel);

	public:
		MuxBtn(uint8_t sigPin, uint8_t muxCH);
		void begin();
		BtnState read();

};
#endif
