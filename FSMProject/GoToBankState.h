#pragma once

#include <iostream>
#include "Player.h"

class GoToBankState : public State<Player>
{
public:

	static GoToBankState* Instance();

	int goldInBank = 0;

	virtual void Enter(Player* entity) override;
	virtual void Execute(Player* entity) override;
	virtual void Exit(Player* entity) override;

	virtual bool OnMessage(Player* entity, const Message& msg) override;
};