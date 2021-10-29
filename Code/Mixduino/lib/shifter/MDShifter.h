
#ifndef ARDUINO_MDSHIFTER_H
#define ARDUINO_MDSHIFTER_H
#include <Arduino.h>
#include <OutputBase.h>
#include <Shifter.h>

class MDShifter : public OutputBase
{
	public:
		MDShifter(int sig, int latch , int clk, int nRegs);
		void setTo(uint8_t pos, int value);
		void clearAll();

	private:
		Shifter* sf;
};
#endif
