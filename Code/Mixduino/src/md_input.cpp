#include "md_input.hpp"
#include "Muxer.hpp"
#include "Mux.hpp"
#include "pin_map.h"
#include "sw_muxmap.h"
#include "midi_map.h"
#include "BtnKit.h"

namespace MDInput
{
  Muxer padl_mux(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A3);
  Muxer padr_mux(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);
  Muxer btnl_mux_p(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A3);
  Muxer btnr_mux_p(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);
  Muxer btnl_mux_s(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A3);
  Muxer btnr_mux_s(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);

  Mux m_padl_mux(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A3);
  Mux m_padr_mux(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);
  Mux decksel_mux(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);

  BtnKit bKit(aSwSet, btn_kit_set, nASw);

  void initPins();

  void initialize() {
    initPins();
    padl_mux.initialize(SwMuxLeftPads, t_pads, lpad_fnote);
    padr_mux.initialize(SWMuxRightPads, t_pads, rpad_fnote);
    btnl_mux_p.initialize(SwMuxLeftSetPrimary, t_mleft_pri, pbtn_l_fnote);
    btnl_mux_s.initialize(SwMuxLeftSetSencondary, t_mleft_sec, sbtn_l_fnote);
    btnr_mux_p.initialize(SWMuxRightSetPrimary, t_mright_pri, pbtn_r_fnote);
    btnr_mux_s.initialize(SWMuxRightSetSecondary, t_mright_sec, sbtn_r_fnote);
    decksel_mux.initialize(sw_deck_sel);
    m_padl_mux.initialize(sw_range_l);
    m_padr_mux.initialize(sw_range_r);
    bKit.initialize();
  }

  void readSelector(void(*selFunc)()){
    decksel_mux.read(selFunc);
  }

  void readPadMode(void(*pModesFunc)(), Location loc){
    if(loc == Location::Left){
      m_padl_mux.read(pModesFunc);
      return;
    }
    m_padr_mux.read(pModesFunc);
  }

  
  void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), uint8_t padl_ch, uint8_t padr_ch) {
    padl_mux.read(funcOn, padl_ch);
    padr_mux.read(funcOn, padr_ch);
    btnl_mux_p.read(funcOn, sw_in_ch);
    btnl_mux_s.read(funcOn, pad_in_ch);
    btnr_mux_p.read(funcOn, sw_in_ch);
    btnr_mux_s.read(funcOn, pad_in_ch);
    bKit.read(funcOn, sw_in_ch);
  }

  void initPins() {
    pinMode(MPLEX_A2, INPUT_PULLUP);
    pinMode(MPLEX_A3, INPUT_PULLUP);
    pinMode(MPLEX_S0, OUTPUT);
    pinMode(MPLEX_S1, OUTPUT);
    pinMode(MPLEX_S2, OUTPUT);
    pinMode(MPLEX_S3, OUTPUT);
  }


} // namespace MDInput
