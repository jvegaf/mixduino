#include "MuxerPots.hpp"
#include "constans.h"

namespace MD
{

  MuxerPots::MuxerPots(Multiplexer4067* muxer, const uint8_t* muxPositions, const uint8_t totalPots)
    : m_muxer{muxer},
      m_muxPositions{muxPositions},
      m_totalPots{totalPots},
      m_cState{new uint16_t[totalPots]()},
      m_pState{new uint16_t[totalPots]()},
      m_lastCcValue{new uint16_t[totalPots]()},
      m_pTime{new uint32_t[totalPots]()}
  {
    
  }

  void MuxerPots::read(inCommand_t c)
  {
    boolean potMoving = false;

    m_cState[c.inputPos] = m_muxer->readChannel(m_muxPositions[c.inputPos]);
    
        uint16_t potVar = abs(m_cState[c.inputPos] - m_pState[c.inputPos]); // calcula a variacao da porta analogica

        if (potVar >= kvarThreshold)
        {
            m_pTime[c.inputPos] = millis(); // armazena o tempo previo
        }
        uint32_t timer = millis() - m_pTime[c.inputPos]; // reseta o timer
        if (timer < kTimeOut)
        { // se o timer for menor que o tempo maximo permitido significa que o potenciometro ainda esta se movendo
            potMoving = true;
        }

        if (potMoving == true)
        { // se o potenciometro ainda esta se movendo, mande o control change
            uint8_t ccValue = map(m_cState[c.inputPos], 0, 1023, 0, 127);
            if (m_lastCcValue[c.inputPos] != ccValue)
            {
                c.funcCC(c.midiNumber, ccValue, c.midiCh);
                m_pState[c.inputPos] = m_cState[c.inputPos];                         // armazena a leitura atual do potenciometro para comparar com a proxima
                m_lastCcValue[c.inputPos] = ccValue;
            }
        }
  }

} // namespace MD
