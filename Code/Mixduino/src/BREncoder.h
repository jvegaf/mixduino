
#ifndef ARDUINO_BRENCODER_H
#define ARDUINO_BRENCODER_H
#include <Arduino.h>
#include <Encoder.h>
#include "pin_map.h"


class BREncoder  
{
	private:
		long oldPosition;
	public:
		BREncoder();
		int readEnc();
};
#endif
