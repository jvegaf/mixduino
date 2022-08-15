#ifndef DECK_H
#define DECK_H

#pragma once
#include <Arduino.h>

class Deck {
public:
   Deck(const uint8_t *notes, void (*Func)(uint8_t, uint8_t, uint8_t), bool isActive)
       : midi_notes(notes), FuncPtr(Func), is_active(isActive) {}

   void handleEvent(uint8_t id, uint8_t value);

   void handleEvent(uint8_t channel, uint8_t number, uint8_t value);

   void changeState() { this->is_active = !this->is_active; }

 private:
   const uint8_t *midi_notes;
   void (*FuncPtr)(uint8_t, uint8_t, uint8_t);
   bool is_active{false};
};

#endif