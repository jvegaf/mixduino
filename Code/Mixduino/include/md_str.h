#pragma once
#include <Arduino.h>

struct muxreqs_str
{
  const uint8_t *muxPins;
  const uint8_t sigPin;
  const uint8_t *positions;
  const uint8_t totalPositions;
};

typedef struct muxreqs_str muxreqs_t;