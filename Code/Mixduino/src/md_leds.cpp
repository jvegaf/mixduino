#include "md_leds.hpp"
#include "midi_values.h"
#include "pin_map.h"
#include "md_leds_map.hpp"
#include <Shifter.h>

namespace MDLeds {

  MDLed_t leds_group[] = {
  fx3_l,
  fx2_l,
  fx1_l,
  play_l,
  cue_l,
  loop_l,
  cue_b,
  cue_a,
  cue_c,
  cue_r,
  play_r,
  loop_r,
  fx3_r,
  fx2_r,
  fx1_r
};

void setValue(uint8_t number, uint8_t value){
    uint8_t pos = number - kfst_note;
    leds_group[pos].setValue(value);
}
} // namespace MDLeds