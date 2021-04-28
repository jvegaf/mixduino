
#include "SRHandler.h"
#include <MIDI.h> // MIDI library (by Forty Seven Effects) >> https://github.com/FortySevenEffects/arduino_midi_library/releases/tag/4.3.1

MIDI_CREATE_DEFAULT_INSTANCE();

/////////////////////////////////////////////
// midi
byte midiCh = 1; // *Canal midi a ser utilizado
byte note = 36; // *Nota mais grave que sera utilizada
byte cc = 1; // *CC mais baixo que sera utilizado

SRHandler regHandler;

// functions declaration
void handleControlChange(byte channel, byte number, byte value);

/////////////////////////////////////////////
void setup() {

  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa
  
  regHandler.begin();

  MIDI.turnThruOff();
  
  /////////////////////////////////////////////
  // Midi in
  MIDI.setHandleControlChange(handleControlChange);
  


}

void loop() {
  MIDI.read();
}


////////////////////////////////////////////
// led feedback
void handleControlChange(byte channel, byte number, byte value) {
  regHandler.valueDidChange(number, value);
}

