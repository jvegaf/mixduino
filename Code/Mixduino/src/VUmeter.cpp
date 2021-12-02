#include "vumeter.hpp"

namespace mixduino
{

    uint8_t dataValues[][2] = {
        {B00000000, B00000000},
        {B00000000, B00000001},
        {B00000000, B00000011},
        {B00000000, B00000111},
        {B00000000, B00001111},
        {B00000000, B00011111},
        {B00000000, B00111111},
        {B00000000, B01111111},
        {B00000000, B11111111},
        {B00000001, B11111111},
        {B00000011, B11111111},
        {B00000111, B11111111},
        {B00001111, B11111111},
        {B00011111, B11111111},
        {B00111111, B11111111},
        {B01111111, B11111111},
        {B11111111, B11111111}};

    VUmeter::VUmeter(uint8_t pinData, uint8_t pinLatch, uint8_t pinClock)
    {
        m_pData = pinData;
        m_pLatch = pinLatch;
        m_pClock = pinClock;
    }

    void VUmeter::begin()
    {
        this->clear();
    }

    void VUmeter::setLevel(uint8_t level)
    {
        uint8_t highData = dataValues[level][0];
        uint8_t lowData = dataValues[level][1];
        digitalWrite(m_pLatch, LOW);
        // shift out lowuint8_t
        shiftOut(m_pData, m_pClock, LSBFIRST, lowData);
        // shift out highuint8_t
        shiftOut(m_pData, m_pClock, LSBFIRST, highData);
        digitalWrite(m_pLatch, HIGH);
    }

    void VUmeter::clear()
    {
        this->setLevel(0);
    }
} // namespace mixduino