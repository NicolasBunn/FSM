#pragma once

#include <set>
#include "Message.h"
#include "GameEntity.h"

class MessageDispatcher
{
	public:
		std::set<Message> priorityQ;
		void Discharge(GameEntity* receiver, const Message& msg);
		MessageDispatcher();
		static MessageDispatcher* Instance();
		void DispatchMessage(int sender_, int receiver_, Message::MessageType msg_,double delay_ = 0.0);
		void DispatchDelayedMessage();

};