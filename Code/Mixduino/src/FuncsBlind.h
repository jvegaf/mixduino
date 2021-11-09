
#ifndef ARDUINO_FUNCSBLIND_H
#define ARDUINO_FUNCSBLIND_H
#include <Arduino.h>
#include "FuncBase.h"

class FuncsBlind  
{
	private:
		FuncBase* _fnsb;
		uint8_t _t_fnsb;

	public:

		FuncsBlind(FuncBase* fnsb, uint8_t t_fnsb)
		{
			_fnsb = fnsb;
			_t_fnsb = t_fnsb;
		}

		void read()
		{
			for (uint8_t i = 0; i < _t_fnsb; i++)
			{
				_fnsb[i].read();
			}
			
		}


};
#endif
