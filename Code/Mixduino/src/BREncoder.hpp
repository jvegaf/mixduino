#pragma once

#include <Arduino.h>
#include <Encoder.h>
#include "pin_map.h"

namespace MDEncoder
{

		void read(void (*scc_func)(uint8_t, uint8_t, uint8_t));

} // namespace MDEncoder
