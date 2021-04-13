#define SHIFTPWM_USE_TIMER2
const int ShiftPWM_latchPin = 8;
const bool ShiftPWM_invertOutputs = false;
const bool ShiftPWM_balanceLoad = false;

/////////////////////////////////////////////
// LIBRARIES
#include <ShiftPWM.h>  // Bit shifter library >> https://github.com/elcojacobs/ShiftPWM - include ShiftPWM.h after setting the pins!x
// If using with ATmega328 - Uno, Mega, Nano...
#include <MIDI.h> // MIDI library (by Forty Seven Effects) >> https://github.com/FortySevenEffects/arduino_midi_library/releases/tag/4.3.1

MIDI_CREATE_DEFAULT_INSTANCE();

/////////////////////////////////////////////
// midi
byte midiCh = 1; // *Canal midi a ser utilizado
byte note = 36; // *Nota mais grave que sera utilizada
byte cc = 1; // *CC mais baixo que sera utilizado

int ccVuLLastValue = 0;
int ccVuRLastValue = 0;

/////////////////////////////////////////////
// Leds
const byte ledNum = 16; // total number of leds used
unsigned char maxBrightness = 255;
unsigned char pwmFrequency = 75;
unsigned int numRegisters = 2;

unsigned int VuL[] = {0, 1, 2, 3, 4, 5, 6, 7}; // VU Master Left
unsigned int VuR[] = {8, 9, 10, 11, 12, 13, 14, 15}; // VU Master Right

unsigned int red = 180;
unsigned int green = 255;
unsigned int blue = 10;
unsigned int yellow = 100;

// functions declaration
void handleControlChange(byte channel, byte number, byte value);

/////////////////////////////////////////////
void setup() {

  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa
  
  MIDI.turnThruOff();
  
  /////////////////////////////////////////////
  // Midi in
  MIDI.setHandleControlChange(handleControlChange);
  
  // Sets the number of 8-bit registers that are used.
  ShiftPWM.SetAmountOfRegisters(numRegisters);

  ShiftPWM.Start(pwmFrequency, maxBrightness);

}

void loop() {
  MIDI.read();
}


////////////////////////////////////////////
// led feedback
void handleControlChange(byte channel, byte number, byte value) {
  
  int value_ = value;
  if (number == 12) {
    if (value_ != ccVuLLastValue) {
      setVURegister(value_, VuL);
      ccVuLLastValue = value;
    }
  }
  if (number == 13) {
    if (value_ != ccVuRLastValue ) {
      setVURegister(value_, VuR);
      ccVuRLastValue = value;
    }
  }
}

void setVURegister (int val, unsigned int pinSet[]) {
  switch (val) {
        case 0:
          for (int i = 0; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          break;
        case 1:
          for (int i = 1; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          ShiftPWM.SetOne(pinSet[0], green);
          break;
        case 2:
          for (int i = 2; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 2; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 3:
          for (int i = 3; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 3; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 4:
          for (int i = 4; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 4; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 5:
          for (int i = 5; i < 7; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 5; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 6:
          for (int i = 6; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 5; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          ShiftPWM.SetOne(pinSet[5], yellow);
          break;
        case 7:
          for (int i = 7; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 6; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          ShiftPWM.SetOne(pinSet[6], yellow);
          break;
        case 8:
          for (int i = 7; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 6; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          ShiftPWM.SetOne(pinSet[6], yellow);
          ShiftPWM.SetOne(pinSet[7], red);
          break;
      }
}
