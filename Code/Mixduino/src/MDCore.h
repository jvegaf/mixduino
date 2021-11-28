
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include "..\lib\npkit\NPKit.h"
#include "Browser.h"
#include "Controller.h"
#include "FXUnit.h"
#include "FuncFactory.h"
#include "Mixer.h"
#include "md_defs.h"
#include <Arduino.h>

enum class DeckSelector
{
	DECK_B,
	DECK_C
};

enum class ModeSelector
{
	HOTCUE_MODE,
	LOOP_MODE,
	FX_MODE,
};

class MDCore
{
public:
	MDCore(
		void (*funcOn)(uint8_t, uint8_t, uint8_t),
		void (*funcOff)(uint8_t, uint8_t, uint8_t),
		void (*funcCC)(uint8_t, uint8_t, uint8_t),
		void (*cbModeFunc)(uint8_t),
		void (*cbSelDeck)())
		: m_funcOn{funcOn},
		  m_funcOff{funcOff},
		  m_funcCC{funcCC},
		  m_cbModeFunc{cbModeFunc},
		  m_cbSelDeck{cbSelDeck}
	{
		m_factory = new FuncFactory();
		m_npkit = new NPKit(NP_DATA, T_NP);
	}

	void begin()
	{
		m_npkit->begin();
		initPins();
		m_factory->begin(m_npkit, m_funcOn, m_funcOff, m_funcCC, m_cbModeFunc, m_cbSelDeck);

		m_deckSelBtn = m_factory->getDeckSelBtn();
		m_mixer = m_factory->getMixer();
		m_leftController = m_factory->getLeftController();
		m_rightController = m_factory->getRightController();
		m_browser = m_factory->getBrowser();
		m_fxUnits = m_factory->getFxUnits();
	}

	void changeSelectedDeck() {

	}

	void changeMode(uint8_t align)
	{

	}

	void readButtons()
	{
		// readDecksMode();	
	}

	void readPots() 
	{

	}

	void onCChange(uint8_t channel, uint8_t number, uint8_t value)
	{
		switch (channel)
		{

		case DECK_A_CH:
			m_leftController->padSetTo(number, value);
			break;

		case DECK_B_CH:
			// m_rightPad->setTo(number, value);
			break;

		case DECK_C_CH:
			// m_rightPad->setTo(number, value);
			break;

		case MIXER_CH: 
			m_mixer->setLevel(number, value);
			break;

		default:
			break;
		}
	}

	void onNoteOn(uint8_t channel, uint8_t number, uint8_t value)
	{
		switch (channel)
		{

		case FX1_CH:
			m_fxUnits[0].setTo(number, value);
			break;

		case FX2_CH:
			m_fxUnits[1].setTo(number, value);
			break;

		case DECK_A_CH:
			m_leftController->playerSetTo(number, value);
			break;

		case DECK_B_CH:
			// _funcs->setTo(number, value);
			break;

		case DECK_C_CH:
			// _funcs->setTo(number, value);
			break;

		case MIXER_CH:
			// _funcs->setTo(number, value);
			break;

		default:
			break;
		}
	}

private:
	void (*m_funcOn)(uint8_t, uint8_t, uint8_t);
	void (*m_funcOff)(uint8_t, uint8_t, uint8_t);
	void (*m_funcCC)(uint8_t, uint8_t, uint8_t);
	void (*m_cbModeFunc)(uint8_t);
	void (*m_cbSelDeck)();
	Controller *m_leftController;
	Controller *m_rightController;
	Mixer *m_mixer;
	Browser *m_browser;
	FXUnit *m_fxUnits;
	ButtonFunc *m_deckSelBtn;
	FuncFactory *m_factory;
	NPKit *m_npkit;

	void initPins();
	void vuChange(uint8_t number, uint8_t value);
	ModeSelector incrementPadMode(ModeSelector mode);
	
};
#endif
