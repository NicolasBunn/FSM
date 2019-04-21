#include "GameEntity.h"

GameEntity::GameEntity(int id_)
	: id(id_)
{

}

GameEntity::~GameEntity()
{

}

void GameEntity::SetId(int id_)
{
	id = id_;
}

int GameEntity::GetId() const
{
	return id;
}