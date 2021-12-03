#pragma once
#include <Arduino.h>

namespace mixduino {
enum class PadMode { HOTCUE, LOOP, FX };

PadMode incrementMode(PadMode mode)
{
  switch (mode)
  {
  case PadMode::HOTCUE :
    return PadMode::LOOP;

  case PadMode::LOOP :
    return PadMode::FX;

  case PadMode::FX :
    return PadMode::HOTCUE;

  }
}

class Deck {
public:
  Deck();


  uint8_t syncmode() const { return m_syncmode; }
  void setSyncmode(const uint8_t &syncmode) { m_syncmode = syncmode; }

  uint8_t statePlay() const { return m_state_play; }
  void setStatePlay(const uint8_t &state_play) { m_state_play = state_play; }

  uint8_t stateCue() const { return m_state_cue; }
  void setStateCue(const uint8_t &state_cue) { m_state_cue = state_cue; }

  uint8_t stateLoop() const { return m_state_loop; }
  void setStateLoop(const uint8_t &state_loop) { m_state_loop = state_loop; }

  PadMode padMode() const { return m_padMode; }
  void changePadMode() { m_padMode = incrementMode(m_padMode); }

  uint8_t *pads() const { return m_pads; }
  void setPads(uint8_t *pads) { m_pads = pads; }
  void setPadTo(uint8_t position, uint8_t value) { m_pads[position] = value; }

private:
  uint8_t *m_pads { nullptr };
  PadMode m_padMode { PadMode::HOTCUE };
  uint8_t m_syncmode { 0 };
  uint8_t m_state_play { 0 };
  uint8_t m_state_cue { 0 };
  uint8_t m_state_loop { 0 };
};
} // namespace mixduino
