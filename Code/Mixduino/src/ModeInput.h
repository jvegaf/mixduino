
#ifndef ARDUINO_MODEINPUT_H
#define ARDUINO_MODEINPUT_H
#include <Arduino.h>
#include "MuxInput.h"

class ModeInput : public MuxInput
{
	private:

	public:

		ModeInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex);
		boolean read();

};
#endif
