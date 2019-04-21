#include "MessageDispatcher.h"
#include "EntityManager.h"

MessageDispatcher::MessageDispatcher()
{

}

void MessageDispatcher::Discharge(GameEntity* receiver, const Message& msg)
{
	receiver->HandleMessage(msg);
}

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::DispatchMessage(int sender_, int receiver_, Message::MessageType msg_,double delay_)
{
	GameEntity* receiver = EntityManager::Instance()->GetEntityFromId(receiver_);
	Message msg(sender_, receiver_, msg_,delay_);

	if (delay_ <= 0.0)
	{
		Discharge(receiver, msg);
	}
	else
	{
		double currentTime = 0.0f;
		msg.dispatchTime = currentTime + delay_;
		//priorityQ.insert(msg);
	}

}

void MessageDispatcher::DispatchDelayedMessage()
{
	double currentTime = 0.0;

	while ((priorityQ.begin()->dispatchTime < currentTime) && (priorityQ.begin()->dispatchTime > 0.0))
	{
		Message msg = *priorityQ.begin();

		GameEntity* receiver = EntityManager::Instance()->GetEntityFromId(msg.receiver);

		Discharge(receiver, msg);

		priorityQ.erase(priorityQ.begin());
	}
}