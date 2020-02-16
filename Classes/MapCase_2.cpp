#include "MapCase_2.h"

MapCase_2::MapCase_2(Scene* scene, Vec2 position)
{
	RocksMaker = new Rocks;
	PoopMaker = new Poop;
	FireMaker = new Fire;

	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorT(scene, Vec2(position.x, position.y + 111));

	RocksMaker->CreateObject(scene, Vec2(position.x - 100, position.y), 1);
	PoopMaker->CreateObject(scene, Vec2(position), 1);
	FireMaker->CreateObject(scene, Vec2(position.x + 100, position.y), 1);

	Player->objectVec.push_back(RocksMaker);
	Player->objectVec.push_back(PoopMaker);
	Player->objectVec.push_back(FireMaker);

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
