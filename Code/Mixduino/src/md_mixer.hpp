#pragma once

#include <Arduino.h>

/**\
 *  Joined Mixer with Browser and FX effects
 */

class MDMixer {

public:
  MDMixer(const uint8_t *notes, void (*Func)(uint8_t, uint8_t, uint8_t)) : midi_notes(notes), FuncPtr(Func) {}

  void handleEvent(uint8_t id, uint8_t value);
  void handleEvent(uint8_t channel, uint8_t number, uint8_t value);

private:
  const uint8_t *midi_notes;
  void (*FuncPtr)(uint8_t, uint8_t, uint8_t);
};