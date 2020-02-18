#include "MapCase_2.h"

MapCase_2::MapCase_2(Scene* scene, Vec2 position)
{
	for (int i = 0; i < 4; i++)
	{
		RocksMaker[i] = new Rocks;

		if (i >= 2)
			continue;

		PoopMaker[i] = new Poop;
	}

	RocksMaker[0]->CreateObject(scene, Vec2(position.x - 32, position.y - 32), 1);
	RocksMaker[1]->CreateObject(scene, Vec2(position.x - 32, position.y + 32), 2);
	RocksMaker[2]->CreateObject(scene, Vec2(position.x + 32, position.y - 32), 3);
	RocksMaker[3]->CreateObject(scene, Vec2(position.x + 32, position.y + 32), 5);
	PoopMaker[0]->CreateObject(scene, Vec2(position.x - 170, position.y + 80), 1);
	PoopMaker[1]->CreateObject(scene, Vec2(position.x+ 170, position.y - 80), 1);

	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorT(scene, position);

	RoomNumber = 2;
	RoomClear = false;
}

MapCase_2::~MapCase_2()
{
}

void MapCase_2::tick()
{
	if (mapLT->getPosition().x - mapLT->getContentSize().width < Player->getIsaacBody()->getPosition().x &&
		mapLT->getPosition().x + mapLT->getContentSize().width > Player->getIsaacBody()->getPosition().x &&
		mapLT->getPosition().y - mapLT->getContentSize().height < Player->getIsaacBody()->getPosition().y &&
		mapLT->getPosition().y + mapLT->getContentSize().height > Player->getIsaacBody()->getPosition().y)
	{
		Player->setRoomNumber(RoomNumber);
	}

	
	this->CollisionToDoor();
}
