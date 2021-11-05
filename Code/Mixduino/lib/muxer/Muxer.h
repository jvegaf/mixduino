
#ifndef MUXER_H
#define MUXER_H
#include <Arduino.h>
#include <input_base.h>

class Muxer : public InputBase
{

public:
	Muxer(uint8_t sig, const uint8_t *mPins, const uint8_t nPins)
	{
		_muxSIG = sig;
		_totalMuxPins = nPins;
		_muxPins = new uint8_t[_totalMuxPins];
		for (uint8_t i = 0; i < _totalMuxPins; i++)
		{
			_muxPins[i] = mPins[i];
		}

		_pState = new int[_totalMuxPins]();
		_cState = new int[_totalMuxPins]();
		_lastdebouncetime = new unsigned long[_totalMuxPins]();
	}

	void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t), uint8_t midCh)
	{
		pinMode(_muxSIG, INPUT_PULLUP);
		pinMode(_muxPins[0], OUTPUT);
		pinMode(_muxPins[1], OUTPUT);
		pinMode(_muxPins[2], OUTPUT);
		pinMode(_muxPins[3], OUTPUT);

		fnon = funcOn;
		fnoff = funcOff;
		_midiChannel = midCh;
	}

	void read(uint8_t input_pos, uint8_t noteIndex)
	{
		setMuxChannel(input_pos);
		_cState[input_pos] = digitalRead(_muxSIG);

		if ((millis() - _lastdebouncetime[input_pos]) > _debouncedelay)
		{
			if (_pState[input_pos] != _cState[input_pos])
			{
				_lastdebouncetime[input_pos] = millis();

				if (_cState[input_pos] == LOW)
				{
					fnon(noteIndex, 127, _midiChannel);
				}
				else
				{
					fnoff(noteIndex, 127, _midiChannel);
				}
				_pState[input_pos] = _cState[input_pos];
			}
		}
	}

	State read(uint8_t input_pos)
	{
		setMuxChannel(input_pos);
		_cState[input_pos] = digitalRead(_muxSIG);

		if ((millis() - _lastdebouncetime[input_pos]) > _debouncedelay)
		{
			if (_pState[input_pos] != _cState[input_pos])
			{
				_lastdebouncetime[input_pos] = millis();

				_pState[input_pos] = _cState[input_pos];
				if (_cState[input_pos] == LOW)
				{
					return State::STATE_HIGH;
				}
				else
				{
					return State::STATE_LOW;
				}
			}
			return State::STATE_SAME;
		}
	}

private:
	uint8_t _muxSIG;
	uint8_t *_muxPins;
	uint8_t _totalMuxPins;
	int *_pState;
	int *_cState;
	uint8_t _midiChannel;

	unsigned long *_lastdebouncetime;
	unsigned long _debouncedelay = 20;

	void setMuxChannel(uint8_t channel);
	void (*fnon)(uint8_t, uint8_t, uint8_t);
	void (*fnoff)(uint8_t, uint8_t, uint8_t);
};
#endif
