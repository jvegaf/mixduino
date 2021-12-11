#pragma once

#include "Input.h"

namespace MD
{
  class Pot
  {
  public:
    Pot(Input* input);
    Pot() = default;
    void read(inCommand_t c);
  private:
    Input* m_input{nullptr};
  };
  
} // namespace MD
