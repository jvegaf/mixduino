#pragma once
#include <Arduino.h>
#include <Encoder.h>

namespace mixduino
{
class MDEncoder
{

public:
  MDEncoder(uint8_t pin_a, uint8_t pin_b);
  void read(EventManager &em);

private:
  int32_t m_oldPosition { -10 };
  Encoder* const m_encoder;
};

} // namespace mixduino
