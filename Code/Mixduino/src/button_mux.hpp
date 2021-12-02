#pragma once
#include <Arduino.h>
#include <EventManager.h>

namespace mixduino
{
class MuxButton
{

public:
  MuxButton(const uint8_t* muxPins, const uint8_t sigPin, const uint8_t* positions, const uint8_t tPositions);
  void read(EventManager &em, const uint8_t firstKey);

private:
  const uint8_t* m_muxPins { nullptr };
  const uint8_t m_sigPin { 0 };
  const uint8_t* m_positions { nullptr };
  const uint8_t m_tPositions { 0 };
  uint16_t* m_pState { nullptr };
  uint16_t* m_cState { nullptr };

  uint32_t* m_lastDebounceTime { nullptr };

  void setMuxChannel(uint8_t channel);
};
} // namespace mixduino

