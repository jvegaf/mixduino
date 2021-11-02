
#ifndef ARDUINO_MDMODE_H
#define ARDUINO_MDMODE_H
#include <Arduino.h>

class MDMode
{
	public: 
		MDMode(const uint8_t* mxPins, uint8_t sig, uint8_t position);
		void begin();
		void read();
		uint8_t getMode();
		uint8_t getModeColor();

     private: 
	 	enum deckModeColor {
				HOTCUE_MODE_COLOR = 1,
				LOOP_MODE_COLOR   = 2,
				FX_MODE_COLOR     = 7
			}; 
		enum deckMode { 
			HOTCUE_MODE = 0,
			LOOP_MODE   = 8,
			FX_MODE     = 16
		};
		uint8_t _mxSigPin;
		const uint8_t *_mxPins;
		uint8_t _position;
		int _pState;
		int _cState;
		unsigned long _lastdebouncetime;
		unsigned long debouncedelay = 20;
		deckMode _dMode;
		deckModeColor _dmColor;

	void setMuxChannel(uint8_t channel);
	void incrementMode();
};
#endif
