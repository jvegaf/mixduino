#include "vu.hpp"

VU::VU(uint8_t p_data, uint8_t p_latch, uint8_t p_clock)
: m_data_pin{p_data}, m_latch_pin{p_latch}, m_clock_pin{p_clock}
{ }

void VU::begin() {
	pinMode(m_data_pin, OUTPUT);
	pinMode(m_latch_pin, OUTPUT);
	pinMode(m_clock_pin, OUTPUT);
    this->clear();
}

void VU::setLevel(uint16_t level)
{
    digitalWrite(m_latch_pin, LOW);
    // shift out lowbyte
    shiftOut(m_data_pin, m_clock_pin, LSBFIRST, level);
    // shift out highbyte
    shiftOut(m_data_pin, m_clock_pin, LSBFIRST, (level >> 8));
    digitalWrite(m_latch_pin, HIGH);
}

void VU::clear()
{
    this->setLevel(0);
}