
#ifndef ARDUINO_MDMODEFUNC_H
#define ARDUINO_MDMODEFUNC_H
#include <Arduino.h>
#include "MDState.h"
#include <MDFunc.h>

class MDModeFunc : public MDFunc
{
	public:
		MDModeFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos );
		MDState read(); 

	private:
};
#endif
