#pragma once

#include <iostream>

#include "GameEntity.h"
#include "State.h"
#include "StateMachine.h"

class Player : public GameEntity
{
public:
	int totalGold;
	int energy;
	int goldCarried;
	int thirst;
	const int maxGold = 5;
	StateMachine<Player>* fsm;

	Player(int energy_ = 100, int thirst_ = 100);
	~Player();
	virtual void Update() override;

	void ChangeState(State<Player>* newState);

	void DisplayStat() const;

	void CreateFSM();

	virtual bool HandleMessage(const Message& msg) override;
};