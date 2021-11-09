#pragma once
#ifndef MD_FUNCS_H
#define MD_FUNCS_H
#include <Arduino.h>
#include "Func.h"

class Funcs  
{
	private:
		Func* _fns;
		uint8_t _t_fns;

	public:
		Funcs(Func* fns, uint8_t t_fns)
		{
			_fns = fns;
			_t_fns = t_fns;
		}

		void read()
		{
			for (uint8_t i = 0; i < _t_fns; i++)
			{
				_fns[i].read();
			}
		}

		void setTo(uint8_t pos, uint8_t value)
		{
			_fns[pos].setTo(value);
		}

};
#endif
