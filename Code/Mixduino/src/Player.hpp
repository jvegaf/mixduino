#pragma once
#include "Component.hpp"

namespace MD
{
  class Player
  {
  public:
    Player(Component* comps, const uint8_t* midiNumbers);
    void read(inCommand_t c);
    void setTo(uint8_t pos, uint8_t value);

  private:
    Component* m_comps{nullptr};
    const uint8_t* m_midiNumbers{nullptr};
  };
  
} // namespace MD
