#pragma once

#include "md_str.h"
#include "Container.hpp"

namespace MD {
class Input {
public:
  Input();
  virtual void read(inCommand_t c) = 0;
  virtual void read(uint8_t inPos, Container* container)=0;
};

class InputPot
{
public:
  InputPot();
  virtual void read(inCommand_t c) = 0;
};

} // namespace MD
