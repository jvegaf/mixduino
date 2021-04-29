
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class NPKit  
{
	private:
		byte firstNumber;

		void handleON(byte number);
		void handleHotCUE(byte number, byte value);

		void clearAll();

	public:
		NPKit(byte firstNum);
		void begin();
		void handleON(byte number, byte value);
		void handleOFF(byte number);


};
#endif
