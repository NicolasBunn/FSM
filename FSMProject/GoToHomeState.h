#pragma once

#include <iostream>
#include "Player.h"

class GoToHomeState : public State<Player>
{
public:
	static GoToHomeState* Instance();

	virtual void Enter(Player* entity) override;
	virtual void Execute(Player* entity) override;
	virtual void Exit(Player* entity) override;

	virtual bool OnMessage(Player* entity, const Message& msg) override;
};