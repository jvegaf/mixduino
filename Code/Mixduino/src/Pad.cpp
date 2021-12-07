#include "Pad.hpp"  
#include "constans.h"
#include "np_conf.h"

namespace MD
{

  Pad::Pad(Button* padBtns, ButtonMode* mode, uint8_t* inPos, uint8_t* outPos, uint8_t firstMidiNumber)
    : m_padBtns{padBtns},
      m_mode{mode},
      m_inPos{inPos},
      m_outPos{outPos},
      m_firstMidiNumber{firstMidiNumber}
  {

  }

  void Pad::changeMode() 
  {
      switch (m_padMode)
      {
      case PadMode::HOTCUE_MODE :
        m_firstMidiNumber = kLoopModeNumber;
        setAllTo(kLoopModeColor);
        m_padMode = PadMode::LOOP_MODE;
          break;

      case PadMode::LOOP_MODE :
        m_firstMidiNumber = kFXModeNumber;
        setAllTo(kFXModeColor);
        m_padMode = PadMode::FX_MODE;
          break;
      
      case PadMode::FX_MODE :
          m_firstMidiNumber = kHotcueModeNumber;
          setHotCueColors();
          m_padMode = PadMode::HOTCUE_MODE;
          break;
      }
  }

  void Pad::setMidiCh(uint8_t midiCh)
  {
      m_midiCh = midiCh;
  }

  void Pad::read() 
  {
      m_mode->read(m_inPos[kTPadButtons], this);
  }

  void Pad::setHotCueColor(uint8_t pos, uint8_t value)
  {
    m_hotcues[pos] = value;
    if (m_padMode == PadMode::HOTCUE_MODE)
    {
        setHotCueColors();
    }
  }


  void Pad::setTo(uint8_t position, uint8_t value)
  {
    m_padBtns[position].setTo(m_outPos[position], value);
  }


  void Pad::setHotCueColors() 
  {
    for (uint8_t i = 0; i < kTPadButtons; i++)
    {
        setTo(i, m_hotcues[i]);
    }
    m_mode->setTo(m_outPos[kTPadButtons], kBlueColor);
  }
    
  void Pad::setAllTo(uint8_t value)
  {
    for (auto i = 0; i < kTPadButtons; i++)
    {
        m_padBtns[i].setTo(m_outPos[i], value);
    }
    m_mode->setTo(m_outPos[kTPadButtons], value);
  }
} // namespace MD

