#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include "midi_map.h"
#include "MDCore.h"
#include "BREncoder.h"
#include "PotKit.h"
#include "TouchKit.h"
// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

BREncoder encL(L_BROWSER_A, L_BROWSER_B);
BREncoder encR(R_BROWSER_A, R_BROWSER_B);
PotKit pots;
// Muxer leftBtns(MPLEX_A3, SwMuxLeftSet, nSwMuxLeft, LEFT_BTNS_CH);
// Muxer rightBtns(MPLEX_A2, SWMuxRightSet, nSwMuxRight, RIGHT_BTNS_CH);
// HWBtn btns(aSwSet, nASw);

MDCore mdCore;
TouchKit touchBars;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value);
void readButtons();
void readPots();
void readEncoder();
void readTouchBars();
void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup()
{
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
 
  pots.begin();
  // leftBtns.begin();
  // rightBtns.begin();
  // btns.begin(ARDUINO_BTNS_CH);
  mdCore.begin();
  touchBars.begin();
  // Send monitor state
  // MIDI.sendNoteOn(SEND_MON_STATE, 127, 1);

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

void loop()
{
  cpu.run();
  MIDI.read();
  readEncoder();
  readTouchBars();
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore.cChange(channel, number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  if (value < 1U)
  {
    mdCore.noteOff(channel, number, value);
    return;
  }
  mdCore.noteOn(channel, number, value);
}

void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore.noteOff(channel, number, value);
}

// void handleActiveSensing() {
//   MIDI.sendRealTime(midi::ActiveSensing);
// }

void readButtons()
{
  // leftBtns.read(sendMidiNoteOn, sendMidiNoteOff);
  // rightBtns.read(sendMidiNoteOn, sendMidiNoteOff);
  // btns.read(sendMidiNoteOn, sendMidiNoteOff);
}

void readPots()
{
  pots.read(sendMidiCC);
}

void readEncoder()
{
  encL.readEnc(sendMidiCC);
  encR.readEnc(sendMidiCC);
}

void readTouchBars()
{
  touchBars.touchRead(sendMidiCC);
}

void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendNoteOn(number, value, channel);
}

void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendNoteOff(number, value, channel);
}

void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendControlChange(number, value, channel);
}
