#pragma once

#include <Arduino.h>

class Mux
{
private:
	uint8_t muxS0;
	uint8_t muxS1;
	uint8_t muxS2;
	uint8_t muxS3;
	uint8_t muxSIG;
	uint8_t position{0};
	uint16_t pState{0};
	uint16_t cState{0};

	unsigned long lastdebouncetime;
	unsigned long debouncedelay = 20;
	
	void setMuxChannel(uint8_t channel);

public:
	Mux(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t sig);
	void initialize(uint8_t pos);
	void read(void (*func)());
};
