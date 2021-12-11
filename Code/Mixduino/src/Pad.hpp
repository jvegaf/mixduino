#pragma once
#include "Container.hpp"
#include "ButtonCBack.hpp"
#include "Button.hpp"
#include "md_str.h"


namespace MD
{
  enum class PadMode { HOTCUE_MODE, LOOP_MODE, FX_MODE };
  
  class Pad : 
  {
    public:
      Pad(Button* padBtns, ButtonCBack* mode);
      void setCBackFn(void(*cbFunc)(uint8_t));
      void changeMode();
      void read(inCommand_t p);
      void setHotCueColor(uint8_t pos, uint8_t value);
      
    private:
      PadMode m_padMode{PadMode::HOTCUE_MODE};
      void(*m_cbFunc)(uint8_t);
      uint8_t* m_hotcues{nullptr};
      Button* m_padBtns{nullptr};
      ButtonCBack* m_mode{nullptr};
      uint8_t m_firstMidiNumber{0};

      void setTo(uint8_t position, uint8_t value);
      void setHotCueColors();
      void setAllTo(uint8_t value);
  };
} // namespace MD

