#pragma once

#include "GameEntity.h"
#include "State.h"
#include "StateMachine.h"

class Barman : public GameEntity
{
public:
	Barman(int v);
	State<Barman>* currentState;
	StateMachine<Barman>* fsm;
	virtual void Update() override;
	void CreateFSM();
	virtual bool HandleMessage(const Message& msg) override;
	void ChangeState(State<Barman>* newState);
};
