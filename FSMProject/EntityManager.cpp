#include "EntityManager.h"

EntityManager* EntityManager::Instance()
{
	static EntityManager instance;
	return &instance;
}

EntityManager::EntityManager()
{

}

void EntityManager::RegisterEntity(GameEntity* newEntity)
{
	entityMap[newEntity->GetId()] = newEntity;
}

GameEntity* EntityManager::GetEntityFromId(int id) 
{
	EntityMap::iterator it;

	it = entityMap.find(id);

	if (it != entityMap.end())
	{
		return it->second;
	}

	return nullptr;
}

void EntityManager::RemoveEntity(int id)
{
	EntityMap::iterator it;

	it = entityMap.find(id);
	if (it != entityMap.end())
	{
		entityMap.erase(it);
	}
}