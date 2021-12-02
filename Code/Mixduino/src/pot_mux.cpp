#include "pot_mux.hpp"
#include "constants.h"

namespace mixduino {

MuxPot::MuxPot(const muxreqs_t reqs)
    : m_mplex{new Multiplexer4067(reqs.muxPins[0], reqs.muxPins[1], reqs.muxPins[2],
                                  reqs.muxPins[3], reqs.sigPin)},
      m_positions{reqs.positions},
      m_tPositions{reqs.totalPositions}, m_pState{new uint16_t[reqs.totalPositions]()},
      m_cState{new uint16_t[reqs.totalPositions]()},
      m_pTime{new uint32_t[reqs.totalPositions]()},
      m_timer{new uint32_t[reqs.totalPositions]()} {}

void MuxPot::begin() { m_mplex->begin(); }

void MuxPot::read(EventManager &em,  const uint16_t *evKeys) {
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

      uint16_t result = evKeys[i] << 8 | ccValue;
      em.queueEvent(EventManager::kEventAnalog0, result);
      m_pState[i] = m_cState[i];
    }
  }
}
} // namespace mixduino
