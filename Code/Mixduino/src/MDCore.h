
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include "Func.h"
#include "FuncFactory.h"
#include "FuncMode.h"
#include "NPKit.h"
#include "Pad.h"
#include "Funcs.h"
#include "FuncsBlind.h"
#include "VUmeter.h"
#include "md_defs.h"
#include <Arduino.h>

enum class State
{
	STATE_ON,
	STATE_OFF
};

uint8_t const t_VUSet = 5;

class MDCore
{
public:

	MDCore()
	{
		_factory = new FuncFactory();
		_npkit = new NPKit(NP_DATA, T_NP);
		_vuSet = new VUmeter[t_VUSet];
		_vuSet[0] = VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK);
		_vuSet[1] = VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK);
		_vuSet[2] = VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK);
		_vuSet[3] = VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK);
		_vuSet[4] = VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK);
	}

	void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
	{
		_npkit->begin();
		initPins();
		_factory->begin(_npkit, funcOn, funcOff);
		for (uint8_t i = 0; i < t_VUSet; i++)
		{
			_vuSet[i].begin();
		}

		_leftFuncMode = _factory->getFuncModeLeft();
		_rightFuncMode = _factory->getFuncModeRight();
		_funcsBlind = _factory->getBlindFuncs();
		_funcs = _factory->getFuncs();
		_leftPad = _factory->getLeftPad();
		_rightPad = _factory->getRightPad();
		checkDeckMode(_leftFuncMode, _leftPad);
		checkDeckMode(_rightFuncMode, _rightPad);
	}

	void readButtons()
	{
		readDecksMode();
		_funcsBlind->read();
		_funcs->read();
		_leftPad->read();
		_rightPad->read();
	}

	void onCChange(uint8_t channel, uint8_t number, uint8_t value)
	{
		switch (channel)
		{
		case VUMETERS_CH: // VU
			vuChange(number, value);
			break;

		default:
			break;
		}
	}
	void onNoteChange(State state, uint8_t channel, uint8_t number, uint8_t value)
	{
		switch (channel)
		{

		case IN_OUT_CH:
			if (state == State::STATE_ON)
			{
				_funcs->setTo(number, value);
			}
			if (state == State::STATE_OFF)
			{
				_funcs->setTo(number, LOW);
			}
			break;

		case LEFT_PAD_CH:
			handlePadNoteChange(state, _leftFuncMode, _leftPad, number, value);
			break;

		case RIGHT_PAD_CH:
			handlePadNoteChange(state, _rightFuncMode, _rightPad, number, value);
			break;

		default:
			break;
		}
	}

private:
	VUmeter *_vuSet;
	FuncFactory *_factory;
	NPKit *_npkit;
	FuncMode *_leftFuncMode;
	FuncMode *_rightFuncMode;
	Pad *_leftPad;
	Pad *_rightPad;
	Funcs* _funcs;
	FuncsBlind* _funcsBlind;

	void initPins();
	void handlePadNoteChange(State nState, FuncMode *deckMD, Pad *pad, uint8_t number, uint8_t value);
	void vuChange(uint8_t number, uint8_t value);
	void readDecksMode();
	void checkDeckMode(FuncMode *fm, Pad *p);
	// void setInitialDeckB();
};
#endif
