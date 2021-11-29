#include "VUmeter.hpp"

namespace feedback
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

    VUmeter::VUmeter(uint8_t p_data, uint8_t p_latch, uint8_t p_clock)
    {
        data_pin = p_data;
        latch_pin = p_latch;
        clock_pin = p_clock;
    }

    void VUmeter::begin()
    {
        pinMode(data_pin, OUTPUT);
        pinMode(latch_pin, OUTPUT);
        pinMode(clock_pin, OUTPUT);
        this->clear();
    }

    void VUmeter::setLevel(uint8_t level)
    {
        uint8_t highData = dataValues[level][0];
        uint8_t lowData = dataValues[level][1];
        digitalWrite(latch_pin, LOW);
        // shift out lowuint8_t
        shiftOut(data_pin, clock_pin, LSBFIRST, lowData);
        // shift out highuint8_t
        shiftOut(data_pin, clock_pin, LSBFIRST, highData);
        digitalWrite(latch_pin, HIGH);
    }

    void VUmeter::clear()
    {
        this->setLevel(0);
    }
} // namespace feedback