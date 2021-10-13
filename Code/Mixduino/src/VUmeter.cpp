#include "VUmeter.h"

int dataValues[] = {
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
    this->clear();
}

void VUmeter::setLevel(uint8_t level)
{
    int dataLevel = dataValues[level];
    digitalWrite(latch_pin, LOW);
    // shift out lowuint8_t
    shiftOut(data_pin, clock_pin, LSBFIRST, dataLevel);
    // shift out highuint8_t
    shiftOut(data_pin, clock_pin, LSBFIRST, (dataLevel >> 8));
    digitalWrite(latch_pin, HIGH);
}

void VUmeter::clear()
{
    this->setLevel(0);
}