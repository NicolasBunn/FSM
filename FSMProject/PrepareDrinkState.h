#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Barman.h"

class PrepareDrinkState : public State<Barman>
{
public:
	static PrepareDrinkState* Instance();

	virtual void Enter(Barman* entity) override;
	virtual void Execute(Barman* entity) override;
	virtual void Exit(Barman* entity) override;

	virtual bool OnMessage(Barman* entity, const Message& msg) override;
};