#pragma once
#include "Button.hpp"

namespace MD
{
  class Player
  {
  public:
    Player(Button* btns, const uint8_t* inPositions, const uint8_t* outPositions, const uint8_t* midiNumbers);
    void setMidiChannel(uint8_t midiCh);
    void setMidiFunctions(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
    void read();
    void setTo(uint8_t pos, uint8_t value);

  private:
    Button* m_btns{nullptr};
    const uint8_t* m_inPositions{nullptr};
    const uint8_t* m_outPositions{nullptr};
    const uint8_t* m_midiNumbers{nullptr};
    uint8_t m_midiCh{0};
    void (*m_funcOn)(uint8_t, uint8_t, uint8_t);
    void (*m_funcOff)(uint8_t, uint8_t, uint8_t);
  };
  
} // namespace MD
