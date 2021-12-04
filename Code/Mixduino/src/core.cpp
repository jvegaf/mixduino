#include "core.hpp"

namespace mixduino
{

    void Core::begin()
    {
        for (size_t i = 0; i < kTotalVUes; i++)
        {
          m_vues[i].begin();
        }

        npk.begin();
    }

    void Core::cChange(uint8_t channel, uint8_t number, uint8_t value)
    {
        switch (channel)
        {
        case 12: // VU
            vuChange(number, value);
            break;
        case 14: // NPixels
            npChange(number, value);
            break;

        default:
            break;
        }
    }

    void Core::noteOn(uint8_t channel, uint8_t number, uint8_t value)
    {
        for (uint8_t i = 0; i < nFbRight; i++)
        {
            if (fbRightSet[i] == number)
            {
                m_shftrs[0].setPin(i, HIGH);
                m_shftrs[0].write();
                return;
            }
        }

        for (uint8_t i = 0; i < nFbLeft; i++)
        {
            if (fbLeftSet[i] == number)
            {
                m_shftrs[1].setPin(i, HIGH);
                m_shftrs[1].write();
                return;
            }
        }
    }


    void Core::vuChange(uint8_t number, uint8_t value)
    {
        m_vues[number].setLevel(value);
    }

    void Core::npChange(uint8_t position, uint8_t value)
    {
        npk.handleChange(position, value);
    }

    void Core::setInitialDeckB()
    {
        this->npChange(NP_DECK_SEL, 1);
    }
} // namespace mixduino
