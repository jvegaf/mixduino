#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

namespace MD
{
//////////////////////////////////////
// NEOPIXELS

static const uint8_t NP_PADL1    = 0;
static const uint8_t NP_PADL2    = 1;
static const uint8_t NP_PADL3    = 2;
static const uint8_t NP_PADL4    = 3;
static const uint8_t NP_PADL5    = 4;
static const uint8_t NP_PADL6    = 5;
static const uint8_t NP_PADL7    = 6;
static const uint8_t NP_PADL8    = 7;
static const uint8_t NP_MODE_L   = 8;
static const uint8_t NP_SYNC_L   = 9;
static const uint8_t NP_PADR_1   = 10;
static const uint8_t NP_PADR_2   = 11;
static const uint8_t NP_PADR_3   = 12;
static const uint8_t NP_PADR_4   = 13;
static const uint8_t NP_PADR_5   = 14;
static const uint8_t NP_PADR_6   = 15;
static const uint8_t NP_PADR_7   = 16;
static const uint8_t NP_PADR_8   = 17;
static const uint8_t NP_DECK_SEL = 18;
static const uint8_t NP_MODE_R   = 19;
static const uint8_t NP_SYNC_R   = 20;

static const uint8_t T_PIXELS = 21;

static const uint8_t PIXLS_PAD_L[] = {
    NP_PADL1,
    NP_PADL2,
    NP_PADL3,
    NP_PADL4,
    NP_PADL5,
    NP_PADL6,
    NP_PADL7,
    NP_PADL8};

static const uint8_t PIXLS_PAD_R[] = {
    NP_PADR_1,
    NP_PADR_2,
    NP_PADR_3,
    NP_PADR_4,
    NP_PADR_5,
    NP_PADR_6,
    NP_PADR_7,
    NP_PADR_8};

static const uint8_t kBrigthness = 32;

static const uint32_t kClearColor   = Adafruit_NeoPixel::Color(0, 0, 0);
static const uint32_t kBlueColor    = Adafruit_NeoPixel::Color(0, 0, 255);
static const uint32_t kGreenColor   = Adafruit_NeoPixel::Color(0, 255, 0);
static const uint32_t kRedColor     = Adafruit_NeoPixel::Color(255, 0, 0);
static const uint32_t kYellowColor  = Adafruit_NeoPixel::Color(255, 230, 0);
static const uint32_t kOrangeColor  = Adafruit_NeoPixel::Color(255, 143, 0);
static const uint32_t kPurpleColor  = Adafruit_NeoPixel::Color(243, 0, 255);
static const uint32_t kGrayColor    = Adafruit_NeoPixel::Color(128, 128, 128);
static const uint32_t kMagentaColor = Adafruit_NeoPixel::Color(255, 0, 255);
static const uint32_t kMaroonColor  = Adafruit_NeoPixel::Color(128, 0, 0);

static const uint32_t kColors[] = {
    kClearColor,  // no hotcue
    kBlueColor,   // cue
    kOrangeColor, // fade in
    kYellowColor, // fade out
    kRedColor,    // load
    kGrayColor,   // Grid
    kGreenColor,  // loop
    kPurpleColor,
    kMagentaColor,
    kMaroonColor
};

static const uint8_t kHotcueModeColor = 0;
static const uint8_t kLoopModeColor   = 6;
static const uint8_t kFXModeColor     = 7;
    
} // namespace MD


