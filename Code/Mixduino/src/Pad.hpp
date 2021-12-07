#pragma once
#include "Container.hpp"
#include "ButtonMode.hpp"
#include "Button.hpp"


namespace MD
{
  enum class PadMode { HOTCUE_MODE, LOOP_MODE, FX_MODE };
  
  class Pad : public Container
  {
    public:
      Pad(Button* padBtns, ButtonMode* mode, uint8_t* inPos, uint8_t* outPos, uint8_t firstMidiNumber);
      void changeMode() override;
      void setMidiCh(uint8_t midiCh);
      void read();
      void setHotCueColor(uint8_t pos, uint8_t value);
    private:
      PadMode m_padMode{PadMode::HOTCUE_MODE};
      uint8_t* m_hotcues{nullptr};
      Button* m_padBtns{nullptr};
      ButtonMode* m_mode{nullptr};
      uint8_t* m_inPos{nullptr};
      uint8_t* m_outPos{nullptr};
      uint8_t m_firstMidiNumber{0};
      uint8_t m_midiCh{0};

      void setTo(uint8_t position, uint8_t value);
      void setHotCueColors();
      void setAllTo(uint8_t value);
  };
} // namespace MD

