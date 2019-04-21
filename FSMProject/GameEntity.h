#pragma once

#include "Message.h"

class GameEntity
{
	private:
		int id;

		void SetId(int id_);

	public:
		GameEntity(int id_);
		virtual ~GameEntity();
		virtual void Update() = 0;
		int GetId() const;

		virtual bool HandleMessage(const Message& msg) = 0;

};