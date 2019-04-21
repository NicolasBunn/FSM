#include <iostream>

#include "Player.h"
#include "Barman.h"
#include "EntityManager.h"
#include "StateMachine.h"
#include "GoToRiverState.h"
#include "CleanBarState.h"

int main()
{
	Barman barman(1);
	Player player(30, 20);
	Message msg(0, 0, Message::MessageType::drinkInPreparation);

	player.CreateFSM();
	barman.CreateFSM();

	player.fsm->SetCurrentState(GoToRiverState::instance());
	barman.fsm->SetCurrentState(CleanBarState::Instance());
	
	EntityManager::Instance()->RegisterEntity(&player);
	EntityManager::Instance()->RegisterEntity(&barman);

	while (player.totalGold < 20)
	{
		player.fsm->Update();
		barman.fsm->Update();
	}
	
	int end;

	std::cout << "Enter a value to exit the program " << std::endl;
	std::cin >> end;

	return 0;
}