#include "pot.hpp"
#include "constants.h"

namespace mixduino
{

Pot::Pot(uint8_t* positions, uint8_t tPositions)
  : m_tPositions{ tPositions },
    m_positions{ positions },
    m_pState{ new uint16_t[tPositions]()},
    m_cState{new uint16_t[tPositions]()},
    m_pTime{ new uint32_t[tPositions]()},
    m_timer{ new uint32_t[tPositions]()}
{

}

void Pot::read(EventManager &em, uint8_t firstkey) {
  for (uint8_t i = 0; i < m_tPositions; i++) {
    m_cState[i] = analogRead(m_positions[i]);
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
