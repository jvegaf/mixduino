#pragma once
#include <Arduino.h>
#include <EventManager.h>
#include <Multiplexer4067.h>


namespace mixduino {
class MuxPot {
public:
  MuxPot(uint8_t *muxPins, uint8_t sigPin, uint8_t *positions,
      uint8_t totalPositions);
  void begin();
  void read(EventManager &em, uint8_t key);

private:
  Multiplexer4067 *m_mplex{nullptr};
  const uint8_t *m_positions{nullptr};
  const uint8_t m_tPositions{0};
  uint16_t *m_pState{nullptr};
  uint16_t *m_cState{nullptr};
  uint32_t *m_pTime{nullptr};
  uint32_t *m_timer{nullptr};

};

} // namespace mixduino
