#include "Barman.h"

Barman::Barman(int v)
	:GameEntity(1)
{
	fsm = new StateMachine<Barman>(this);
}

void Barman::Update()
{

}


void Barman::CreateFSM()
{
	fsm = new StateMachine<Barman>(this);
}

bool Barman::HandleMessage(const Message& msg)
{
	return fsm->HandleMessage(msg);
}

void Barman::ChangeState(State<Barman>* newState)
{
	fsm->ChangeState(newState);
}