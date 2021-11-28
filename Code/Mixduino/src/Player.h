#pragma once
#ifndef MD_PLAYER_H
#define MD_PLAYER_H
#include "Pot.h"
#include "ButtonMidi.h"
#include "md_defs.h"

class Player
{
public:
    Player(ButtonMidi* pBtns, Pot* tPot)
    : _playerBtns{pBtns}, _tempoPot{tPot}
    {
    }

    void read()
    {
        _tempoPot->read();
        for (uint8_t i = 0; i < T_PLAYER_BTNS; i++)
        {
            _playerBtns[i].read();
        }
        
    }

    void setMidiChannel(uint8_t channel)
    {
        _tempoPot->setMidiChannel(channel);
        for (uint8_t i = 0; i < T_PLAYER_BTNS; i++)
        {
            _playerBtns[i].setMidiChannel(channel);
        }
    }

    void setTo(uint8_t number, uint8_t value)
    {
        _playerBtns[number].setTo(value);
    }

private:
    Pot* const  _tempoPot { nullptr };
    ButtonMidi* const  _playerBtns { nullptr };
};

#endif