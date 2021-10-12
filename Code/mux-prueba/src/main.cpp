#include <Arduino.h>

const int muxSIG  = A3;
const int muxS0   = 47;
const int muxS1   = 49;
const int muxS2   = 40;
const int muxS3   = 53;

const int entradasmplex = 16;
int mux[entradasmplex] = {0};
int vpmux[entradasmplex] = {0};


unsigned long lastdebouncetime[entradasmplex] = {0};
unsigned long debouncedelay = 20;


void SetMuxChannel(byte channel)
{
  digitalWrite(muxS0, bitRead(channel, 0));
  digitalWrite(muxS1, bitRead(channel, 1));
  digitalWrite(muxS2, bitRead(channel, 2));
  digitalWrite(muxS3, bitRead(channel, 3));
}


void setup()
{
  pinMode(muxSIG, INPUT_PULLUP);
  pinMode(muxS0, OUTPUT);
  pinMode(muxS1, OUTPUT);
  pinMode(muxS2, OUTPUT);
  pinMode(muxS3, OUTPUT);

  Serial.begin(9600);
}

  void loop()
{
  for (int i = 0; i <= 15; i++) {
    
    SetMuxChannel(i);
    
    mux[i] = digitalRead(muxSIG);
    if ((millis() - lastdebouncetime[i]) > debouncedelay)
    {
      if (vpmux[i] != mux[i])
      {
      lastdebouncetime[i] = millis();

        if (mux[i] == LOW)
        {
         //MIDI.sendNoteOn(36 + i , 127 , 1);
          Serial.print(i);
          Serial.println("....ON");
        }
        else {
          //MIDI.sendNoteOff(36 + i , 127 , 1);
           Serial.print(i);
           Serial.println(" .   OFF");

        }
        vpmux[i] = mux[i];

      }
    }
  }
}