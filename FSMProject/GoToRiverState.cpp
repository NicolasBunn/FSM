#include "GoToRiverState.h"
#include "GoToBarState.h"
#include "GoToHomeState.h"
#include "GoToBankState.h"

GoToRiverState* GoToRiverState::instance()
{
	static GoToRiverState instance;
	return &instance;
}

void GoToRiverState::Enter(Player* entity)
{
	srand(time(NULL));
	std::cout << "Enter go to river State " << std::endl;
}

void GoToRiverState::Execute(Player* entity)
{
	std::cout << "Searching gold in River " << std::endl;

	entity->thirst -= 10;
	entity->energy -= 5;

	int goldRandom = rand() % 5;
	if (goldRandom == 0)
	{
		std::cout << "Didn't find any gold " << std::endl;
	}
	else
	{
		std::cout << "Find " << goldRandom  << " golds " << std::endl;
		entity->goldCarried += goldRandom;
		entity->totalGold += goldRandom;
		if (entity->goldCarried > entity->maxGold)
		{
			entity->goldCarried = entity->maxGold;
		}
		entity->DisplayStat();

	}

	if (entity->thirst < 20)
	{
		std::cout << "I thirsty go to the bar !" << std::endl;
		entity->ChangeState(GoToBarState::Instance());
	}
	else if (entity->energy < 10)
	{
		std::cout << "I am tired go home ! " << std::endl;
		entity->ChangeState(GoToHomeState::Instance());
	}
	else if (entity->goldCarried >= entity->maxGold)
	{
		std::cout << "Too much gold , go to the bank " << std::endl;
		entity->ChangeState(GoToBankState::Instance());
	}
}

void GoToRiverState::Exit(Player* entity)
{
	std::cout << "Exit go to river state " << std::endl;
}

bool GoToRiverState::OnMessage(Player* entity, const Message& msg)
{
	return false;
}

