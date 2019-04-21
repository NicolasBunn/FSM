#pragma once

template<class T>
#pragma once

#include "Message.h"

class State
{
	public:
		virtual ~State() {};
		virtual void Enter(T* entity) = 0;
		virtual void Execute(T* entity) = 0;
		virtual void Exit(T* entity) = 0;

		virtual bool OnMessage(T* entity, const Message& msg) = 0;
};
