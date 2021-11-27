
#ifndef MUX_ANALOG_INPUT_H
#define MUX_ANALOG_INPUT_H
#include "AnalogInput.h"
#include "Multiplexer4067.h"

class MuxAnalogInput : public AnalogInput
{
public:
	MuxAnalogInput(uint8_t inputPos, Multiplexer4067 *mux)
		: AnalogInput{inputPos}, _mux{mux}
	{
	}

	MuxAnalogInput() = default;

	void read(inputStr_t in) override
	{
		_cState = _mux->readChannel(_inPos);

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
				in.funCC(in.midiNumber, ccValue, in.midiChannel); // envia Control Change (numero do CC, valor do CC, canal midi)
				_pState = _cState;								  // armazena a leitura atual do potenciometro para comparar com a proxima
				_lastCcValue = ccValue;
			}
		}
	}

protected:
	Multiplexer4067 *_mux { nullptr };
};
#endif
