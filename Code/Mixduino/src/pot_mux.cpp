#include "pot_mux.hpp"
#include "constants.h"

namespace mixduino {

MuxPot::MuxPot(uint8_t *muxPins, uint8_t sigPin, uint8_t *positions,
         uint8_t totalPositions)
    : m_mplex{new Multiplexer4067(muxPins[0], muxPins[1], muxPins[2],
                                  muxPins[3], sigPin)},
      m_positions{positions},
      m_tPositions{totalPositions}, m_pState{new uint16_t[totalPositions]()},
      m_cState{new uint16_t[totalPositions]()},
      m_pTime{new uint32_t[totalPositions]()},
      m_timer{new uint32_t[totalPositions]()} {}

void MuxPot::begin() { m_mplex->begin(); }

void MuxPot::read(EventManager &em, uint8_t firstkey) {
  for (uint8_t i = 0; i < m_tPositions; i++) {
    m_cState[i] = m_mplex->readChannel(m_positions[i]);
  }

  for (uint8_t i = 0; i < m_tPositions; i++) {

    uint16_t potVar = abs(m_cState[i] - m_pState[i]);
    boolean potMoving = false;

    if (potVar >= kTHRESHOLD) {
      m_pTime[i] = millis();
    }
    m_timer[i] = millis() - m_pTime[i];
    if (m_timer[i] < kTIMEOUT) {

      potMoving = true;
    }

    if (potMoving == true) {
      uint8_t ccValue = map(m_cState[i], 0, 1023, 0, 127);
      uint8_t key = firstkey + i;
      uint16_t result = key & ccValue;
      em.queueEvent(EventManager::kEventAnalog0, result);
      m_pState[i] = m_cState[i];
    }
  }
}
} // namespace mixduino
