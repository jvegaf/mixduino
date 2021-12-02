#pragma once
#include <Arduino.h>
#include <EventManager.h>

namespace mixduino {
class Pot {

public:
  Pot(const uint8_t* positions, const uint8_t tPositions);
  void read(EventManager &em, const uint16_t *evKeys);

private:
  const uint8_t m_tPositions{0};
  const uint8_t *m_positions{nullptr};
  uint16_t *m_pState{nullptr};
  uint16_t *m_cState{nullptr};
  uint32_t *m_pTime{nullptr};
  uint32_t *m_timer{nullptr};

};
} // namespace mixduino
