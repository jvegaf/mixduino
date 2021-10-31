
#ifndef MDSHIFTER_H
#define MDSHIFTER_H
#include <Arduino.h>
#include <output_base.h>
#include <Shifter.h>

class MDShifter : public OutputBase
{
	private:
		Shifter* sf;

	public:
		MDShifter(int sig, int latch , int clk, int nRegs)
		{
		    this->sf = new Shifter(sig, latch, clk, nRegs);
		}

		MDShifter() = default;

		void setTo(OutDTO od)
		{
		    this->sf->setPin(od.position, od.state);
		    this->sf->write();
		}

		void clearAll() {
			this->sf->setAll(LOW);
		    this->sf->write();
		}

};
#endif
