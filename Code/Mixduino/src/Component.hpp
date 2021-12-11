#pragma once

#include "md_str.h"

namespace MD
{
  class Component
  {
  public:
    Component();
    virtual void read(inCommand_t c);
  };
} // namespace MD
