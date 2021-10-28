#include "MDCore.h"


VUmeter vuL1 = VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK);
VUmeter vuL2 = VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK);
VUmeter vuL3 = VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK);
VUmeter vuML = VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK);
VUmeter vuMR = VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK);

VUmeter vuSet[] = {vuL1, vuL2, vuL3, vuML, vuMR};

NPKit npk;

void MDCore::begin()
{
    vuL1.begin();
    vuL2.begin();
    vuL3.begin();
    vuML.begin();
    vuMR.begin();
    npk.begin();
}

void MDCore::cChange(uint8_t channel, uint8_t number, uint8_t value)
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

void MDCore::noteOn(uint8_t channel, uint8_t number, uint8_t value)
{

}

void MDCore::noteOff(uint8_t channel, uint8_t number, uint8_t value)
{

}

void MDCore::vuChange(uint8_t number, uint8_t value)
{
    vuSet[number].setLevel(value);
}

void MDCore::npChange(uint8_t position, uint8_t value)
{
    // npk.handleChange(position, value);
}
