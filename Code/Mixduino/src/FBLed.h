#pragma once
#ifndef FBLED_H
#define FBLED_H
#include <Arduino.h>
#include "Output.h"
#include <Shifter.h>

class FBLed : public Output
{
	private:
		Shifter* _shft;

	public:

		FBLed(Shifter* shf, uint8_t outPos);
		FBLed() = default;
		void setTo(uint8_t value);

};
#endif
