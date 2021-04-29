#include <Arduino.h>
#include <MIDI.h>
#include "NPKit.h"
MIDI_CREATE_DEFAULT_INSTANCE();



/////////////////////////////////////////////
// midi
byte midiCh = 1;
byte note = 36;
byte cc = 1;

/////////////////////////////////////////////
// NeoPixels Module
NPKit neoPx(note); // first number to receive changes (in this case is equals to lowest midi note)


void handleNoteOn(byte channel, byte number, byte value);
void handleNoteOff(byte channel, byte number, byte value);

void setup() {
  neoPx.begin();
  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa

  MIDI.turnThruOff();
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

}

void loop() {
  MIDI.read();
}

void handleNoteOn(byte channel, byte number, byte value) {
  neoPx.handleON(number, value);
}

void handleNoteOff(byte channel, byte number, byte value) {
  neoPx.handleOFF(number);
}

