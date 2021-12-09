#pragma once

#include "md_str.h"
#include "Container.hpp"

namespace MD {
class Input {
public:
  virtual void read(inCommand_t c) = 0;
  virtual void read(uint8_t inPos, Container* container)=0;
};

class InputPot
{
public:
  virtual void read(inCommand_t c) = 0;
};

} // namespace MD
