#pragma once

#include <Arduino.h>
#include <Shifter.h>

struct MDLed_t
{
  Shifter* shf_ptr;
  uint8_t input_position;

  explicit MDLed_t(Shifter* s_ptr, uint8_t pos);

  void setValue(uint8_t value) {  
    boolean next = false;
    if(value > 0 ) {
      next = true;
    }
    shf_ptr->setPin(input_position, next);
  }
};

MDLed_t::MDLed_t(Shifter* s_ptr, uint8_t pos)
  : shf_ptr(s_ptr),
    input_position(pos)
{}