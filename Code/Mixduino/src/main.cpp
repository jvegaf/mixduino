
#include "BREncoder.hpp"
#include "PotKit.h"
#include "components_def.h"
#include "deck.hpp"
#include "md_controller.h"
#include "md_init.h"
#include "md_input.hpp"
#include "md_mixer.hpp"
#include "md_pad.hpp"
#include "md_touch.hpp"
#include "midi_map.h"
#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>


// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

PotKit pots;

ThreadController cpu;     // thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);

MDMixer mixer(mixer_notes, sendMidiNoteOn);

Deck deckA(deck_A_notes, sendMidiNoteOn, true);
Deck deckB(deck_B_notes, sendMidiNoteOn, true);
Deck deckC(deck_C_notes, sendMidiNoteOn, false);

Pad padA(pad_A_notes, sendMidiNoteOn, true);
Pad padB(pad_C_notes, sendMidiNoteOn, true);
Pad padC(pad_C_notes, sendMidiNoteOn, false);

void changeDeck();

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void handleEvent(uint8_t component_id, uint8_t value);
void handleEvent(uint8_t channel, uint8_t number, uint8_t value);
void readButtons();
void readPots();
void readTouchBars();
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup() {
  // Serial.begin(31250);
  MD::initPins();
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
  pots.begin();
  // Set Deck B Focus
  // MIDI.onNoteOn(1, 127, 9);

  /////////////////////////////////////////////
  // threads
  // pots
  threadReadPots.setInterval(10);
  threadReadPots.onRun(readPots);
  cpu.add(&threadReadPots);

  // buttons
  threadReadButtons.setInterval(20);
  threadReadButtons.onRun(readButtons);
  cpu.add(&threadReadButtons);
}

void loop() {
  cpu.run();
  MIDI.read();
  MDEncoder::read(sendMidiCC);
  MDTouch::read(sendMidiCC);
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value) {
  // MDFeedback::onCChange(channel, number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value) {
  // MDFeedback::onNoteOn(channel, number, value);
}

void changeDeck() {
  deckB.changeState();
  deckC.changeState();
  padB.changeState();
  padC.changeState();
}

void readButtons() { MDInput::read(handleEvent); }

void readPots() { pots.read(sendMidiCC); }

void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel) { MIDI.sendNoteOn(number, value, channel); }

void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel) { MIDI.sendControlChange(number, value, channel); }

inline void handleEvent(uint8_t comp, uint8_t value) {
  switch (comp) {
    /** Mixer browser fx*/
  case 12 ... 26:
    mixer.handleEvent(comp, value);
    break;

  case 27:
    padA.changeMode(Location::Left);
    break;

  case 28 ... 31:
    deckA.handleEvent(comp, value);
    break;

  case 32: {
    padB.changeMode(Location::Right);
    padC.changeMode(Location::Right);
  } break;

  case 33 ... 40:
    deckB.handleEvent(comp, value);
    deckC.handleEvent(comp, value);
    break;

  case 41 ... 48:
    padA.handleEvent(comp, value);
    break;

  case 49 ... 56:
    padB.handleEvent(comp, value);
    padC.handleEvent(comp, value);
    break;

  default:
    break;
  }
}

inline void handleEvent(uint8_t channel, uint8_t number, uint8_t value) {
  switch (number) {
  case 13 ... 26:
    mixer.handleEvent(channel, number, value);
    break;

  case 28 ... 31:
    deckA.handleEvent(channel, number, value);
    break;

  case 33 ... 36:
    deckB.handleEvent(channel, number, value);
    break;

  case 37 ... 40:
    deckC.handleEvent(channel, number, value);
    break;

  case 41 ... 48:
    padA.handleEvent(channel, number, value);
    break;

  case 49 ... 56:
    padB.handleEvent(channel, number, value);
    break;

  case 57 ... 64:
    padC.handleEvent(channel, number, value);
    break;

  default:
    break;
  }
}