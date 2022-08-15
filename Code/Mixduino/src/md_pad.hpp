#pragma once

#include <Arduino.h>
#include "md_controller.h"
#include "md_colors.h"
#include "midi_map.h"

class Pad
{
public:
  Pad(const uint8_t *notes, void (*Func)(uint8_t, uint8_t, uint8_t), bool active) : midi_notes(notes), noteFunc(Func), is_active(active) {}

  void changeMode(Location loc);
  void changeState() { this->is_active = !this->is_active; }

  void handleEvent(uint8_t id, uint8_t value);
  void handleEvent(uint8_t channel, uint8_t number, uint8_t value);

  private:
    const uint8_t *midi_notes;
    void (*noteFunc)(uint8_t, uint8_t, uint8_t);
    uint8_t hotcueTypes[t_pads]{0};
    uint32_t hc_cols[t_pads] = {MDColor::CLEAR_COL};
    Mode pad_mode{Mode::HotCues};
    bool is_active{false};

    void setHotCueType(uint8_t number, uint8_t type);
    bool idExists(uint8_t id);
    void draw(Location l, uint32_t color);
    void draw(Location l, uint32_t *colors);
};