#include "Muxer.h"
#include "constans.h"

namespace MD
{

Muxer::Muxer(const uint8_t *mxPins, uint8_t sigPin, const uint8_t *swPositions,
             const uint8_t totalSw)
    : m_sigPin{sigPin}, m_mxPins{mxPins}, m_Positions{swPositions},
      m_tPositions{totalSw}, m_pState{new uint16_t[totalSw]()},
      m_cState{new uint16_t[totalSw]()}, m_lastdebouncetime{
                                             new uint32_t[totalSw]()} {}

void Muxer::setMuxChannel(uint8_t channel) {
  digitalWrite(m_mxPins[0], bitRead(channel, 0));
  digitalWrite(m_mxPins[1], bitRead(channel, 1));
  digitalWrite(m_mxPins[2], bitRead(channel, 2));
  digitalWrite(m_mxPins[3], bitRead(channel, 3));
}

void Muxer::read(inMidip_t p) {
  setMuxChannel(m_Positions[p.inputPos]);
  m_cState[p.inputPos] = digitalRead(m_sigPin);
  if ((millis() - m_lastdebouncetime[p.inputPos]) > kDebounceDelay) {
    if (m_pState[p.inputPos] != m_cState[p.inputPos]) {
      m_lastdebouncetime[p.inputPos] = millis();

      m_pState[p.inputPos] = m_cState[p.inputPos];
      if (m_cState[p.inputPos] == LOW) {
        // MIDI.sendNoteOn(number , value(127) , channel);
        p.funcOn(p.midiNumber, kMidiMaxValue, p.midiCh);
        return;
      }
      p.funcOff(p.midiNumber, kMidiMaxValue, p.midiCh);
    }
  }
}

void Muxer::read(uint8_t inPos, Container* container) {
  setMuxChannel(m_Positions[inPos]);
  m_cState[inPos] = digitalRead(m_sigPin);
  if ((millis() - m_lastdebouncetime[inPos]) > kDebounceDelay) {
    if (m_pState[inPos] != m_cState[inPos]) {
      m_lastdebouncetime[inPos] = millis();

      if (m_cState[inPos] == LOW) {
        // MIDI.sendNoteOn(number , value(127) , channel);
        container->changeMode();
      }

      m_pState[inPos] = m_cState[inPos];
    }
  }
}
  
} // namespace MD

