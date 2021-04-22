
#ifndef ARDUINO_BRENCODER_H
#define ARDUINO_BRENCODER_H
#include <Arduino.h>
#include <Encoder.h> // Encoder library >> https://github.com/PaulStoffregen/Encoder


class BREncoder  
{
	private:
		long oldPosition;
	public:
		BREncoder();
		~BREncoder();
		int read();
};
#endif
