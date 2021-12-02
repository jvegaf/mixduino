#pragma once
#include <Arduino.h>

namespace mixduino
{

	class VUmeter
	{
	private:
		uint8_t m_pData;
		uint8_t m_pLatch;
		uint8_t m_pClock;
		void clear();

	public:
		VUmeter(uint8_t pinData, uint8_t pinLatch, uint8_t pinClock);
		void begin();
		void setLevel(uint8_t level);
	};
} // namespace mixduino
