#include "touchbar.hpp"
#include "constants.h"

namespace mixduino {

TouchBar::TouchBar(uint16_t i2cAddr) : m_trill{new Trill}, m_i2cAddr{i2cAddr} {}

void TouchBar::begin() {
  m_trill->setup(Trill::TRILL_BAR, m_i2cAddr);
  m_trill->setScanSettings(kScanSpeed, kScanNumBits);
}

void TouchBar::read(EventManager &em, uint16_t key) {
  m_trill->read();

  if (m_trill->getNumTouches() > 0) {
    uint8_t location = m_trill->touchLocation(0) / 25;
    uint16_t result = key << 8 | location;
    em.queueEvent(EventManager::kEventUser0, result);
  }
}
} // namespace mixduino
