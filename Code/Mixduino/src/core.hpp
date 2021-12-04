
#pragma once
#include "np_map.h"
#include "constants.h"
#include "npixel.hpp"
#include "pin_map.h"
#include "sr_fb_map.h"
#include "vumeter.hpp"
#include <Align.h>
#include <Shifter.h>


namespace mixduino {

class Core {
public:
  void begin();
  void cChange(uint8_t channel, uint8_t number, uint8_t value);
  void noteOn(uint8_t channel, uint8_t number, uint8_t value);
  void noteOff(uint8_t channel, uint8_t number, uint8_t value);

private:
  VUmeter m_vues[kTotalVUes]{
    VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK),
    VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK),
    VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK),
    VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK),
    VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK)
  };
  Shifter m_shftrs[kTotalShifters]{
    Shifter(FBR_SIG, FBR_LATCH, SRCLK, 1),
    Shifter(FBL_SIG, FBL_LATCH, SRCLK, 1)
  };
  NPixel npk{ NPixel(NP_DATA, nNP) };
  void vuChange(uint8_t number, uint8_t value);
  void npChange(uint8_t position, uint8_t value);
  void setInitialDeckB();
};
} // namespace mixduino
