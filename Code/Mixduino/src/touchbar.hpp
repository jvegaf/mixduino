#pragma once
#include <Arduino.h>
#include <Trill.h>
#include <EventManager.h>

namespace mixduino {
class TouchBar {
public:
  TouchBar(uint16_t i2cAddr);
  void begin();
  void read(EventManager &em, uint16_t key);
private:
  Trill* m_trill{nullptr};
  const uint16_t m_i2cAddr{0};
};

} // namespace mixduino
