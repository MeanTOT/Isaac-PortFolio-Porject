#include "MapCase_1.h"

MapCase_1::MapCase_1(Scene* scene, Vec2 position)
{
	RocksMaker[0] = new Rocks;
	RocksMaker[1] = new Rocks;

	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorR(scene, Vec2(position.x + 200,position.y));
	this->CreateNormalDoorL(scene, Vec2(position.x - 200, position.y));
	this->CreateNormalDoorT(scene, Vec2(position.x, position.y + 111));
	this->CreateNormalDoorB(scene, Vec2(position.x, position.y - 111));

	RocksMaker[0]->CreateRockBaseMent(scene, Vec2(position.x - 100, position.y), 1);
	RocksMaker[1]->CreateRockBaseMent(scene, Vec2(position.x + 100, position.y), 1);

	Player->objectVec.push_back(RocksMaker[0]);
	Player->objectVec.push_back(RocksMaker[1]);

	RoomNumber = 1;
	RoomClear = false;
}

MapCase_1::~MapCase_1()
{
}

void MapCase_1::tick()
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
