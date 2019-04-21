#include "CleanBarState.h"
#include "PrepareDrinkState.h"

CleanBarState* CleanBarState::Instance()
{
	static CleanBarState instance;
	return &instance;
}


void CleanBarState::Enter(Barman* entity)
{

}

void CleanBarState::Execute(Barman* entity)
{

}

void CleanBarState::Exit(Barman* entity)
{

}

bool CleanBarState::OnMessage(Barman* entity, const Message& msg)
{
	entity->ChangeState(PrepareDrinkState::Instance());

	return false;
}