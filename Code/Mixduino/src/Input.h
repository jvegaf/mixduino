#pragma once
#ifndef MD_INPUT_H
#define MD_INPUT_H
#include <Arduino.h>
#include "input_str.h"

class Input  
{

	public:
		virtual void read(inputStr_t in)=0;

};
#endif
