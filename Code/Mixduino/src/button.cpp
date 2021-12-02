#include "button.hpp"
#include "constants.h"
#include <EventManager.h>

namespace mixduino
{

    Button::Button(const uint8_t *pins, const uint8_t tPins)
    : m_pins { pins }, m_tPins { tPins }
    {
        m_pState = new uint16_t[m_tPins]();
        m_cState = new uint16_t[m_tPins]();
        m_lastDebounceTime = new uint32_t[m_tPins]();
    }

    void Button::read(EventManager &em, const uint16_t *evkeys)
    {

        for (uint8_t i = 0; i < m_tPins; i++)
        {
            m_cState[i] = digitalRead(m_pins[i]);
        }

        for (uint8_t i = 0; i < m_tPins; i++)
        {

            if ((millis() - m_lastDebounceTime[i]) > kDEBOUNCEDELAY)
            {

                if (m_cState[i] != m_pState[i])
                {
                    m_lastDebounceTime[i] = millis();

                    if (m_cState[i] == LOW)
                    {
                        em.queueEvent(EventManager::kEventKeyPress, evkeys[i]);
                    }
                    else
                    {
                        em.queueEvent(EventManager::kEventKeyRelease, evkeys[i]);
                    }

                    m_pState[i] = m_cState[i];
                }
            }
        }
    }
} // namespace mixduino
