#include "PrepareDrinkState.h"
#include "CleanBarState.h"
#include "MessageDispatcher.h"

PrepareDrinkState* PrepareDrinkState::Instance()
{
	static PrepareDrinkState instance;
	return &instance;
}


void PrepareDrinkState::Enter(Barman* entity)
{
	std::cout << "Drink in preparation " << std::endl;
}

void PrepareDrinkState::Execute(Barman* entity)
{
	std::cout << "Drink is ready " << std::endl;
	MessageDispatcher::Instance()->DispatchMessage(entity->GetId(), 0, Message::MessageType::drinkIsReady);

	entity->ChangeState(CleanBarState::Instance());
}

void PrepareDrinkState::Exit(Barman* entity)
{

}

bool PrepareDrinkState::OnMessage(Barman* entity, const Message& msg)
{
	return false;
}