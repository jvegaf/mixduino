#ifndef __VUMETERS_HPP__
#define __VUMETERS_HPP__

#pragma once

#include <Arduino.h>

namespace VUmeters
{
  void initialize();

  void setLevel(uint8_t number, uint8_t value);
} // namespace VUmeters

#endif // __VUMETERS_HPP__