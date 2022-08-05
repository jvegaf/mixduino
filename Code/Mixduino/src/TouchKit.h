#pragma once

#include <Arduino.h>
#include <Trill.h>

namespace MD {

class TouchKit {
private:
public:
  TouchKit();
  void begin();
  void touchRead(void (*scc_func)(uint8_t, uint8_t, uint8_t));
};

} // namespace MD