
#ifndef ARDUINO_NP_COLORS_H
#define ARDUINO_NP_COLORS_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#pragma once

const uint32_t CLEAR_COLOR  = Adafruit_NeoPixel::Color(0, 0, 0);
const uint32_t BLUE_COLOR   = Adafruit_NeoPixel::Color(0, 0, 255);
const uint32_t GREEN_COLOR  = Adafruit_NeoPixel::Color(0, 255, 0);
const uint32_t RED_COLOR    = Adafruit_NeoPixel::Color(255, 0, 0);
const uint32_t YELLOW_COLOR = Adafruit_NeoPixel::Color(255, 255, 0);
const uint32_t ORANGE_COLOR = Adafruit_NeoPixel::Color(255, 143, 0);
const uint32_t PURPLE_COLOR = Adafruit_NeoPixel::Color(128, 0, 128);
const uint32_t WHITE_COLOR   = Adafruit_NeoPixel::Color(255, 255, 255);
const uint32_t MAGENTA_COLOR   = Adafruit_NeoPixel::Color(255, 0, 255);
const uint32_t MAROON_COLOR   = Adafruit_NeoPixel::Color(128, 0, 0);

#endif