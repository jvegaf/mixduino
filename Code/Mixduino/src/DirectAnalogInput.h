#pragma once
#ifndef MD_DIRECT_ANALOG_INPUT_H
#define MD_DIRECT_ANALOG_INPUT_H
#include "AnalogInput.h"

class DirectAnalogInput : public AnalogInput
{

public:
	DirectAnalogInput(uint8_t inputPos)
		: AnalogInput(inputPos)
	{
	}

	void read(inputStr_t in) override
	{
		_cState = analogRead(_inPos);

		_potVar = abs(_cState - _pState); // calcula a variacao da porta analogica

		if (_potVar >= VAR_THRESHOLD)
		{
			_pTime = millis(); // armazena o tempo previo
		}
		_timer = millis() - _pTime; // reseta o timer
		if (_timer < TIMEOUT)
		{ // se o timer for menor que o tempo maximo permitido significa que o potenciometro ainda esta se movendo
			_potMoving = true;
		}
		else
		{
			_potMoving = false;
		}

		if (_potMoving == true)
		{ // se o potenciometro ainda esta se movendo, mande o control change
			uint8_t ccValue = map(_cState, 0, 1023, 0, 127);
			if (_lastCcValue != ccValue)
			{
				in.funCC(in.midiNumber, ccValue, in.midiChannel);	 // envia Control Change (numero do CC, valor do CC, canal midi)
				_pState = _cState; // armazena a leitura atual do potenciometro para comparar com a proxima
				_lastCcValue = ccValue;
			}
		}
	}
};
#endif
