#pragma once
#include <Arduino.h>
#include <EventManager.h>

namespace mixduino
{
class Button
{

public:
  Button(const uint8_t *pins, const uint8_t tPins);
  void read(EventManager &em, const uint16_t *evKeys);

private:
  const uint8_t *m_pins { nullptr };
  const uint8_t m_tPins { 0 };
  uint16_t *m_pState { nullptr };
  uint16_t *m_cState { nullptr };

  uint32_t *m_lastDebounceTime { nullptr };
};

} // namespace mixduino
