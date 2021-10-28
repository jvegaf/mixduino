
#ifndef ARDUINO_MDFUNC_H
#define ARDUINO_MDFUNC_H
#include <Arduino.h>
#include <InputBase.h>
#include <OutputBase.h>
#include <Mode.h>

#pragma once

struct MDFunc
{
	InputBase* in;
	OutputBase* out;
};

struct PadFunc : public MDFunc
{
	Mode* mode;
};


#endif
