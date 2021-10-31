
#ifndef MUXER_H
#define MUXER_H
#include <Arduino.h>
#include <input_base.h>

class Muxer: public InputBase
{
	private: 
		uint8_t _muxSIG;
		uint8_t* _muxPins;
		uint8_t _totalMuxPins;
		int* _pState;
		int* _cState;

		unsigned long* _lastdebouncetime;
		unsigned long _debouncedelay = 20;
		
		void setMuxChannel(uint8_t channel);

	public: 
		Muxer(uint8_t sig, const uint8_t* mPins, const uint8_t nPins)
		{
		    _muxSIG       = sig;
		    _totalMuxPins = nPins;
		    _muxPins     = new uint8_t[_totalMuxPins];
		    for (uint8_t i = 0; i < _totalMuxPins; i++)
		    {
		        _muxPins[i] = mPins[i];
		    }

		    _pState           = new int[_totalMuxPins]();
		    _cState           = new int[_totalMuxPins]();
		    _lastdebouncetime = new unsigned long[_totalMuxPins]();
		}

		Muxer() = default;

		void begin()
		{
		    pinMode(_muxSIG, INPUT_PULLUP);
		    pinMode(_muxPins[0], OUTPUT);
		    pinMode(_muxPins[1], OUTPUT);
		    pinMode(_muxPins[2], OUTPUT);
		    pinMode(_muxPins[3], OUTPUT);
		}

		MDState::StateType read(uint8_t input_pos)
		{
		    setMuxChannel(input_pos);
		    _cState[input_pos] = digitalRead(_muxSIG);
		    
		    for (uint8_t i = 0; i <= _totalMuxPins; i++)
		    {
		        if ((millis() - _lastdebouncetime[input_pos]) > _debouncedelay)
		        {
		            if (_pState[input_pos] != _cState[input_pos])
		            {
		                _lastdebouncetime[input_pos] = millis();

		                if (_cState[input_pos] == LOW)
		                {
		                _pState[input_pos] = _cState[input_pos];
		                    return MDState::StateType::TURN_OFF;
		                }
		                else
		                {
		                    _pState[input_pos] = _cState[input_pos];
		                    return MDState::StateType::TURN_ON;
		                }
		            }
		        }
		    }
		    return MDState::StateType::SAME_STATE;
		}
};
#endif
