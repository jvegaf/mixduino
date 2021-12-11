#include "InputMuxCBack.hpp"
#include "constans.h"

namespace MD
{
  InputMuxCBack::InputMuxCBack(const uint8_t inPos, const uint8_t* muxPins, const uint8_t sigPin)
    : InputMux(inPos, muxPins, sigPin)
  {
    
  }

  void InputMuxCBack::read(void(*cbFunc)(uint8_t), const uint8_t cType) 
  {
    setMuxChannel(m_inPos);
    uint16_t cState = digitalRead(m_sigPin);
  if ((millis() - m_lastdebouncetime) > kDebounceDelay) {
    if (m_pState != cState) {
      m_lastdebouncetime = millis();

      m_pState = cState;
      if (cState == LOW) {
        // MIDI.sendNoteOn(number , value(127) , channel);
        cbFunc(cType);
        return;
      }
    }
  }
    
  
  }
  
  
} // namespace MD


