#include "InputAnalogMux.hpp"
#include "constans.h"

namespace MD
{

  InputAnalogMux::InputAnalogMux(const uint8_t inPos, const uint8_t* muxPins, const uint8_t sigPin)
    : InputAnalogBase(inPos), m_muxPins{muxPins}, m_sigPin{sigPin}
  {
    
  }

  void InputAnalogMux::read(inCommand_t c)
  {
    boolean potMoving = false;
    setMuxChannel(m_inPos);
    uint16_t cState = analogRead(m_sigPin);
    
    uint16_t potVar = abs(cState - m_pState); // calcula a variacao da porta analogica

        if (potVar >= kvarThreshold)
        {
            m_pTime = millis(); // armazena o tempo previo
        }
        uint32_t timer = millis() - m_pTime; // reseta o timer
        if (timer < kTimeOut)
        { // se o timer for menor que o tempo maximo permitido significa que o potenciometro ainda esta se movendo
            potMoving = true;
        }

        if (potMoving == true)
        { // se o potenciometro ainda esta se movendo, mande o control change
            uint8_t ccValue = map(cState, 0, 1023, 0, 127);
            if (m_lastCcValue != ccValue)
            {
                c.funcCC(c.midiNumber, ccValue, c.midiCh);
                m_pState = cState;                         // armazena a leitura atual do potenciometro para comparar com a proxima
                m_lastCcValue = ccValue;
            }
        }
  }

  void InputAnalogMux::setMuxChannel(const uint8_t channel)
  {
    digitalWrite(m_muxPins[0], bitRead(channel, 0));
    digitalWrite(m_muxPins[1], bitRead(channel, 1));
    digitalWrite(m_muxPins[2], bitRead(channel, 2));
    digitalWrite(m_muxPins[3], bitRead(channel, 3));
  }
  
} // namespace MD
