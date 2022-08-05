#include "InputMux.hpp"
#include "constans.h"

namespace MD {

InputMux::InputMux(const uint8_t inPos, const uint8_t *muxPins,
                   const uint8_t sigPin)
    : InputBase(inPos), m_muxPins{muxPins}, m_sigPin{sigPin} {}

void InputMux::read(inCommand_t c) {
  setMuxChannel(m_inPos);
  uint16_t cState = digitalRead(m_sigPin);
  if ((millis() - m_lastdebouncetime) > kDebounceDelay) {
    if (m_pState != cState) {
      m_lastdebouncetime = millis();

      m_pState = cState;
      if (cState == LOW) {
        // MIDI.sendNoteOn(number , value(127) , channel);
        c.funcOn(c.midiNumber, kMidiMaxValue, c.midiCh);
        return;
      }
      c.funcOff(c.midiNumber, kMidiMaxValue, c.midiCh);
    }
  }
}

void InputMux::setMuxChannel(const uint8_t channel) {
  digitalWrite(m_muxPins[0], bitRead(channel, 0));
  digitalWrite(m_muxPins[1], bitRead(channel, 1));
  digitalWrite(m_muxPins[2], bitRead(channel, 2));
  digitalWrite(m_muxPins[3], bitRead(channel, 3));
}

} // namespace MD
