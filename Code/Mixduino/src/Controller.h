#pragma once
#ifndef MD_CONTROLLER_H
#define MD_CONTROLLER_H

#include "Player.h"
#include "Pad.h"


class Controller  
{

	public:
		Controller(Player* player, Pad* pad)
		: _player{player}, _pad{pad}
		{
		}

		Controller() = default;

		void readButtons()
		{
			
		}

		void readPots()
		{
			
		}

		void playerSetTo(uint8_t number, uint8_t value)
		{
			_player->setTo(number, value);
		}

		void padSetTo(uint8_t number, uint8_t value)
		{
			//  y ahora que ???	
		}

	private:
		Player* _player { nullptr };
		Pad* _pad { nullptr };
};
#endif
