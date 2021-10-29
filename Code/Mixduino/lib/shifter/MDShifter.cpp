#include "MDShifter.h"

MDShifter::MDShifter(int sig, int latch, int clk, int nRegs)
{
    this->sf = new Shifter(sig, latch, clk, nRegs);
}

void MDShifter::setTo(uint8_t pos, int value)
{
    this->sf->setPin(pos, value);
    this->sf->write();
}

void MDShifter::clearAll() {
	this->sf->setAll(LOW);
    this->sf->write();
}
