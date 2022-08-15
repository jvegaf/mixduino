#include "vumeters.hpp"
#include "pin_map.h"
#include "vu.hpp"
/**
 *  vuL1, vuL2, vuL3, vuML, vuMR
 */

namespace VUmeters {

const uint16_t dataValues[] = {
  0x0,
  0x1,
  0x3,
  0x7,
  0xF,
  0x1F,
  0x3F,   
  0x7F,  
  0xFF,
 0x1FF, 
 0x3FF, 
 0x7FF, 
 0xFFF, 
 0x1FFF, 
 0x3FFF, 
 0x7FFF, 
 0xFFFF
 };


const uint8_t t_vues = 5;

VU vues[t_vues] = {
  VU(L1VU_SIG, L1VU_LATCH, SRCLK), 
  VU(L2VU_SIG, L2VU_LATCH, SRCLK), 
  VU(L3VU_SIG, L3VU_LATCH, SRCLK),
  VU(MLVU_SIG, MLVU_LATCH, SRCLK), 
  VU(MRVU_SIG, MRVU_LATCH, SRCLK)
};


void initialize() {
  for (size_t i = 0; i < t_vues; i++) {
    vues[i].begin();
  }
}

void setLevel(uint8_t number, uint8_t value) 
{ 
  vues[number].setLevel(dataValues[value]); 
}

}  // namespace VUmeters
