#include "GoToHomeState.h"
#include "GoToRiverState.h"

GoToHomeState* GoToHomeState::Instance()
{
	static GoToHomeState instance;
	return &instance;
}

void GoToHomeState::Enter(Player* entity)
{
	std::cout << "Enter GoToHomeState " << std::endl;
}

void GoToHomeState::Execute(Player* entity)
{
	std::cout << "ZZZZZZzzzzz  " << std::endl;

	entity->energy += 10;
	entity->thirst -= 1;

	entity->DisplayStat();

	if (entity->energy >= 70)
	{
		entity->ChangeState(GoToRiverState::instance());
	}

}

void GoToHomeState::Exit(Player* entity)
{
	std::cout << "Exit GoToHomeState state " << std::endl;
}

bool GoToHomeState::OnMessage(Player* entity, const Message& msg)
{
	return false;
}
