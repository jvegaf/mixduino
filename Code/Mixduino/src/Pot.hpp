#pragma once

#include "Input.h"
#include "Component.hpp"

namespace MD
{
  class Pot : public Component
  {
  public:
    Pot(Input* input);
    Pot() = default;
    void read(inCommand_t c) override;
  private:
    Input* m_input{nullptr};
  };
  
} // namespace MD
