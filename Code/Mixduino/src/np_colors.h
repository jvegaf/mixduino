
#ifndef ARDUINO_NP_COLORS_H
#define ARDUINO_NP_COLORS_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#pragma once

uint32_t BLUE_COL   = Adafruit_NeoPixel::Color(0, 0, 255);
uint32_t GREEN_COL  = Adafruit_NeoPixel::Color(0, 255, 0);
uint32_t YELLOW_COL = Adafruit_NeoPixel::Color(255, 230, 0);
uint32_t ORANGE_COL = Adafruit_NeoPixel::Color(255, 153, 51);
uint32_t RED_COL    = Adafruit_NeoPixel::Color(255, 0, 0);
uint32_t CLEAR_COL  = Adafruit_NeoPixel::Color(0, 0, 0);

#endif
