#pragma once

#include <Arduino.h>
#include <Shifter.h>

struct MDLed_t
{
  Shifter* const shf_ptr;
  const uint8_t input_position;

  MDLed_t(Shifter* s_ptr, const uint8_t pos): shf_ptr(s_ptr), input_position(pos) {}

  void updateValue(uint8_t value) 
  {
    boolean next = value > 0U;
    shf_ptr->setPin(input_position, next);
  }
};