#include "md_input.hpp"
#include "controller.h"
#include "Muxer.hpp"
#include "Mux.hpp"
#include "pin_map.h"
#include "mux_map.h"
#include "midi_map.h"
#include "BtnKit.h"

namespace MDInput
{
  Muxer left_muxer(mux_pins_arr, l_mux_datapin, left_mux_el, t_pads);
  Muxer right_muxer(mux_pins_arr, r_mux_datapin, right_mux_el, t_pads);


  BtnKit bKit(ard_sw_pins, ard_elements, t_ard_sw);


  void read(void (*func)(uint8_t, State)) {
    left_muxer.read(func);
    right_muxer.read(func);
    bKit.read(func);
  }

  


} // namespace MDInput
