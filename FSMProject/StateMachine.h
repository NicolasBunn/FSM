#pragma once

#include <iostream>
#include "State.h"


template<typename T>
class StateMachine
{
	public:
		T* owner;
		State<T>* currentState;
		State<T>* previousState;
		State<T>* globalState; //Check if useful


		StateMachine(T* owner_)
			: owner(owner_), currentState(nullptr), previousState(nullptr), globalState(nullptr)
		{

		}

		void SetOwner(T* owner_)
		{
			owner = owner_;
			if (!owner)
			{
				std::cout << "owner is null " << std::endl;
			}
			else
			{
				std::cout << "owner is not null " << std::endl;
			}
		}

		void SetCurrentState(State<T>* currentState_)
		{
			currentState = currentState_;
		}

		void SetPreviousState(State<T>* previousState_)
		{
			previousState = previousState_;
		}

		void SetGlobalState(State<T>* globalState_)
		{
			globalState = globalState_;
		}

		void Update() const
		{
			if (globalState)
			{
				globalState->Execute(owner);
			}

			if (currentState)
			{
				currentState->Execute(owner);
			}
			
		}

		void ChangeState(State<T>* newState)
		{
			if (currentState)
			{
				previousState = currentState;
				currentState->Exit(owner);
			}

			currentState = newState;
			currentState->Enter(owner);
		}

		State<T>* GetCurrentState() const
		{
			return currentState;
		}

		State<T>* GetGlobalState() const
		{
			return globalState;
		}

		State<T>* GetPreviousState() const
		{
			return previousState;
		}

		virtual bool HandleMessage(const Message& msg) const
		{
			if (currentState && currentState->OnMessage(owner, msg))
			{
				return true;
			}

			return false;
		}
};