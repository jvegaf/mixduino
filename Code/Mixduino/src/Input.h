#pragma once

#include "md_str.h"

namespace MD {
class Input {
public:
  virtual void read(inCommand_t c) = 0;
};

} // namespace MD
