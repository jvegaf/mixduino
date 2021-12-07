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

  void MuxerPots::read(inPotMidip_t p)
  {
    boolean potMoving = false;

    m_cState[p.inputPos] = m_muxer->readChannel(m_muxPositions[p.inputPos]);
    
        uint16_t potVar = abs(m_cState[p.inputPos] - m_pState[p.inputPos]); // calcula a variacao da porta analogica

        if (potVar >= kvarThreshold)
        {
            m_pTime[p.inputPos] = millis(); // armazena o tempo previo
        }
        uint32_t timer = millis() - m_pTime[p.inputPos]; // reseta o timer
        if (timer < kTimeOut)
        { // se o timer for menor que o tempo maximo permitido significa que o potenciometro ainda esta se movendo
            potMoving = true;
        }

        if (potMoving == true)
        { // se o potenciometro ainda esta se movendo, mande o control change
            uint8_t ccValue = map(m_cState[p.inputPos], 0, 1023, 0, 127);
            if (m_lastCcValue[p.inputPos] != ccValue)
            {
                p.funcCC(p.midiNumber, ccValue, p.midiCh);
                m_pState[p.inputPos] = m_cState[p.inputPos];                         // armazena a leitura atual do potenciometro para comparar com a proxima
                m_lastCcValue[p.inputPos] = ccValue;
            }
        }
  }

} // namespace MD
