#pragma once
#include <Arduino.h>
#include <Encoder.h>

namespace browser
{
	class BREncoder
	{
	private:
		long oldPosition;
		Encoder *enc;

	public:
		BREncoder(uint8_t pin_a, uint8_t pin_b);
		void readEnc(void (*scc_func)(uint8_t, uint8_t, uint8_t));
	};

} // namespace browser
