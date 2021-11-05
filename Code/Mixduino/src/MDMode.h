
#ifndef ARDUINO_MDMODE_H
#define ARDUINO_MDMODE_H
#include <Arduino.h>
#include "np_map.h"

enum class deckMode
{
	HOTCUE_MODE,
	LOOP_MODE,
	FX_MODE
};

class MDMode
{
public:
	MDMode(const uint8_t *mxPins, uint8_t sig, uint8_t position);
	void begin();
	void read();
	deckMode getMode();
	uint8_t getModeNote();
	uint8_t getModeColor();
	uint8_t getSelectorModeColor();
	boolean getCheck();
	void markChecked();

private:
	uint8_t _mxSigPin;
	const uint8_t *_mxPins;
	uint8_t _position;
	int _pState;
	int _cState;
	unsigned long _lastdebouncetime;
	unsigned long debouncedelay = 20;
	deckMode _dMode;
	uint8_t _modeNote;
	uint8_t _modeColor;
	boolean _checked;

	void setMuxChannel(uint8_t channel);
	void incrementMode();
};
#endif
