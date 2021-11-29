#include "MDCore.hpp"

namespace mdcore
{

    feedback::VUmeter vuL1 = feedback::VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK);
    feedback::VUmeter vuL2 = feedback::VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK);
    feedback::VUmeter vuL3 = feedback::VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK);
    feedback::VUmeter vuML = feedback::VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK);
    feedback::VUmeter vuMR = feedback::VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK);

    feedback::VUmeter vuSet[] = {vuL1, vuL2, vuL3, vuML, vuMR};

    Shifter fbRight(FBR_SIG, FBR_LATCH, SRCLK, 1);
    Shifter fbLeft(FBL_SIG, FBL_LATCH, SRCLK, 1);

    feedback::NPKit npk(NP_DATA, nNP);

    void Core::begin()
    {
        vuL1.begin();
        vuL2.begin();
        vuL3.begin();
        vuML.begin();
        vuMR.begin();
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
                fbRight.setPin(i, HIGH);
                fbRight.write();
                return;
            }
        }

        for (uint8_t i = 0; i < nFbLeft; i++)
        {
            if (fbLeftSet[i] == number)
            {
                fbLeft.setPin(i, HIGH);
                fbLeft.write();
                return;
            }
        }
    }

    void Core::noteOff(uint8_t channel, uint8_t number, uint8_t value)
    {
        for (uint8_t i = 0; i < nFbRight; i++)
        {
            if (fbRightSet[i] == number)
            {
                fbRight.setPin(i, LOW);
                fbRight.write();
                return;
            }
        }

        for (uint8_t i = 0; i < nFbLeft; i++)
        {
            if (fbLeftSet[i] == number)
            {
                fbLeft.setPin(i, LOW);
                fbLeft.write();
                return;
            }
        }
    }

    void Core::vuChange(uint8_t number, uint8_t value)
    {
        vuSet[number].setLevel(value);
    }

    void Core::npChange(uint8_t position, uint8_t value)
    {
        Npixel pix(position, value);
        npk.handleChange(pix);
    }

    void Core::setInitialDeckB()
    {
        this->npChange(NP_DECK_SEL, 1);
    }
} // namespace mdcore
