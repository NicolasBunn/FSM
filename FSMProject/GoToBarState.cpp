#include "GoToBarState.h"
#include "GoToHomeState.h"
#include "GoToRiverState.h"
#include "MessageDispatcher.h"
#include "Message.h"

GoToBarState* GoToBarState::Instance()
{
	static GoToBarState instance;
	return &instance;
}

void GoToBarState::Enter(Player* entity)
{
	std::cout << "Enter GoToBarState " << std::endl;
}

void GoToBarState::Execute(Player* entity)
{
	std::cout << "Barman ! A drink please " << std::endl;

	MessageDispatcher::Instance()->DispatchMessage(entity->GetId(), 1, Message::MessageType::drinkInPreparation);

}

void GoToBarState::Exit(Player* entity)
{
	std::cout << "Exit GoToBarState " << std::endl;
}

bool GoToBarState::OnMessage(Player* entity, const Message& msg)
{
	std::cout << "glou glou " << std::endl;

	entity->thirst += 50;
	entity->energy -= 10;

	entity->DisplayStat();

	if (entity->energy <= 10)
	{
		entity->ChangeState(GoToHomeState::Instance());
	}
	else
	{
		entity->ChangeState(GoToRiverState::instance());
	}

	return false;
}

