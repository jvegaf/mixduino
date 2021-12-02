#include "button_mux.hpp"
#include "constants.h"
#include <EventManager.h>


namespace mixduino
{
void MuxButton::setMuxChannel(uint8_t channel)
{
    digitalWrite(m_muxPins[0], bitRead(channel, 0));
    digitalWrite(m_muxPins[1], bitRead(channel, 1));
    digitalWrite(m_muxPins[2], bitRead(channel, 2));
    digitalWrite(m_muxPins[3], bitRead(channel, 3));
}

MuxButton::MuxButton(const muxreqs_t reqs)
:
m_muxPins { reqs.muxPins},
m_sigPin { reqs.sigPin },
m_positions { reqs.positions },
m_tPositions { reqs.totalPositions },
m_pState { new uint16_t[m_tPositions]() },
m_cState { new uint16_t[m_tPositions]() },
m_lastDebounceTime { new uint32_t[m_tPositions]()}
{

}

void MuxButton::read(EventManager &em, const uint16_t *evKeys)
{
    for (uint8_t i = 0; i <= m_tPositions; i++)
    {

        setMuxChannel(m_positions[i]);

        m_cState[i] = digitalRead(m_sigPin);
        if ((millis() - m_lastDebounceTime[i]) > kDEBOUNCEDELAY)
        {
            if (m_pState[i] != m_cState[i])
            {
                m_lastDebounceTime[i] = millis();

                if (m_cState[i] == LOW)
                {
                    //MIDI.sendNoteOn(number , value(127) , channel);
                    em.queueEvent(EventManager::kEventKeyPress, evKeys[i]);
                }
                else
                {
                    em.queueEvent(EventManager::kEventKeyRelease, evKeys[i]);
                    //MIDI.sendNoteOff(36 + i , 127 , 1);
                }

                m_pState[i] = m_cState[i];
            }
        }
    }
}
} // namespace mixduino

