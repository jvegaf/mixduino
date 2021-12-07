#pragma once

#include "md_str.h"
#include "Container.hpp"

namespace MD {
class Input {
public:
  Input();
  virtual void read(inMidip_t p) = 0;
  virtual void read(uint8_t inPos, Container* container)=0;
};

} // namespace MD
