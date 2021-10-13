
#ifndef ARDUINO_MUXER_H
#define ARDUINO_MUXER_H
#include <Arduino.h>

class Muxer
{
private:
	uint8_t muxS0;
	uint8_t muxS1;
	uint8_t muxS2;
	uint8_t muxS3;
	uint8_t muxSIG;
	uint8_t* muxPins;
	uint8_t totalMuxPins;
	int* pState;
	int* cState;

	unsigned long* lastdebouncetime;
	unsigned long debouncedelay = 20;
	
	uint8_t midiChannel;
	void setMuxChannel(uint8_t channel);

public:
	Muxer(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t sig);
	void begin(uint8_t* mPins, uint8_t nPins, uint8_t midiCh);
	void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
};
#endif
