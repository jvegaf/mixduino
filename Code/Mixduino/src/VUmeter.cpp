#include "VUmeter.h"

int vuValues[] = {
    0,
    1,
    3,
    7,
    15,
    31,
    63,
    127,
    255,
    511,
    1023,
    2047,
    4095,
    8191,
    16383,
    32767};

VUmeter::VUmeter(uint8_t p_data, uint8_t p_latch, uint8_t p_clock)
{
    data_pin = p_data;
    latch_pin = p_latch;
    clock_pin = p_clock;
}

void VUmeter::begin() {
	pinMode(data_pin, OUTPUT);
	pinMode(latch_pin, OUTPUT);
	pinMode(clock_pin, OUTPUT);
    digitalWrite(clock_pin, LOW);
    digitalWrite(latch_pin, LOW);
    this->clear();
}

void VUmeter::setLevel(uint8_t level)
{
    digitalWrite(latch_pin, LOW);
    int levelData = vuValues[level];
    shiftOut(data_pin, clock_pin, LSBFIRST, levelData);
    if (levelData > 255)
    {
        shiftOut(data_pin, clock_pin, LSBFIRST, (levelData >> 8));
    }
    digitalWrite(latch_pin, HIGH);
}

void VUmeter::clear()
{
    this->setLevel(0);
}