#include <Arduino.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;

int ccLastValue = 0;

/////////////////////////////////////////////
// midi
byte midiCh = 1; // *Canal midi a ser utilizado
byte note = 36; // *Nota mais grave que sera utilizada
byte cc = 1; // *CC mais baixo que sera utilizado

void setVURegister (int val);
void shiftOut(byte myDataOut);
void handleControlChange(byte channel, byte number, byte value);

void setup() {

  pinMode(latchPin, OUTPUT);

  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa
  
  MIDI.turnThruOff();
  MIDI.setHandleControlChange(handleControlChange);

}

void loop() {
  MIDI.read();
}

void setVURegister (int val) {
  switch (val) {
    case 0:
      shiftOut(0x00);
      break;
    case 1:
      shiftOut(0x80);
      break;

    case 2:
      shiftOut(0xC0);
      break;
    case 3:
      shiftOut(0xE0);
      break;
    case 4:
      shiftOut(0xF0);
      break;
    case 5:
      shiftOut(0xF8);
      break;
    case 6:
      shiftOut(0xFC);
      break;
    case 7:
      shiftOut(0xFE);
      break;
    case 8:
      shiftOut(0xFF);
      break;
  }
}


// the heart of the program
void shiftOut(byte myDataOut) {

  // This shifts 8 bits out MSB first,

  //on the rising edge of the clock,

  //clock idles low

  //internal function setup

  digitalWrite(latchPin, 0);

  int i=0;

  int pinState;

  pinMode(clockPin, OUTPUT);

  pinMode(dataPin, OUTPUT);

  //clear everything out just in case to

  //prepare shift register for bit shifting

  digitalWrite(dataPin, 0);

  digitalWrite(clockPin, 0);

  //for each bit in the byte myDataOut&#xFFFD;

  //NOTICE THAT WE ARE COUNTING DOWN in our for loop

  //This means that %00000001 or "1" will go through such

  //that it will be pin Q0 that lights.

  for (i=7; i>=0; i--)  {

    digitalWrite(clockPin, 0);

    //if the value passed to myDataOut and a bitmask result

    // true then... so if we are at i=6 and our value is

    // %11010100 it would the code compares it to %01000000

    // and proceeds to set pinState to 1.

    if ( myDataOut & (1<<i) ) {

      pinState= 1;

    }

    else {

      pinState= 0;

    }

    //Sets the pin to HIGH or LOW depending on pinState

    digitalWrite(dataPin, pinState);

    //register shifts bits on upstroke of clock pin

    digitalWrite(clockPin, 1);

    //zero the data pin after shift to prevent bleed through

    digitalWrite(dataPin, 0);

  }

  //stop shifting

  digitalWrite(clockPin, 0);

  digitalWrite(latchPin, 1);
}

void handleControlChange(byte channel, byte number, byte value) {

  int value_ = value;
  if (number == 12) {
    if (value_ != ccLastValue) {
      setVURegister(value_);
      ccLastValue = value;
    }
  }
}