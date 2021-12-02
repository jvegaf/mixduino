#pragma once
#include "md_str.h"
#include <Arduino.h>
#include <EventManager.h>

namespace mixduino
{
class MuxButton
{

public:
  MuxButton(const muxreqs_t reqs);
  void read(EventManager &em, const uint16_t *evKeys);

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

