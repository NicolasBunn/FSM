#pragma once

#include <map>
#include "GameEntity.h"

class EntityManager
{
	public:

		using EntityMap = std::map<int, GameEntity*>;

		EntityMap entityMap;
		EntityManager();

		static EntityManager* Instance();
		void RegisterEntity(GameEntity* newEntity);
		GameEntity* GetEntityFromId(int id);
		void RemoveEntity(int id);

};