#include "GoToBankState.h"
#include "GoToRiverState.h"
#include "GoToHomeState.h"

GoToBankState* GoToBankState::Instance()
{
	static GoToBankState instance;
	return &instance;
}

void GoToBankState::Enter(Player* entity)
{
	std::cout << "Enter GoToBankState " << std::endl;
}

void GoToBankState::Execute(Player* entity)
{
	goldInBank += entity->goldCarried;
	entity->goldCarried = 0;

	std::cout << "Put " << entity->goldCarried << " in bank" << std::endl;
	std::cout << "Total in bank " << goldInBank << std::endl;

	entity->energy -= 5;

	entity->DisplayStat();

	if (entity->energy <= 10)
	{
		entity->ChangeState(GoToHomeState::Instance());
	}
	else
	{
		entity->ChangeState(GoToRiverState::instance());
	}
}

void GoToBankState::Exit(Player* entity)
{
	std::cout << "Exit GoToBankState " << std::endl;
}

bool GoToBankState::OnMessage(Player* entity, const Message& msg)
{
	return false;
}
