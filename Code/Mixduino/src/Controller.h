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

	private:
		const Player* _player { nullptr };
		const Pad* _pad { nullptr };
};
#endif
