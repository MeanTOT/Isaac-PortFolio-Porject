#include "MapCase_3.h"

MapCase_3::MapCase_3(Scene * scene, Vec2 position)
{
	RocksMaker = new Rocks;

	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorL(scene, Vec2(position.x - 200, position.y));

	RoomNumber = 3;
	RoomClear = false;
}

MapCase_3::~MapCase_3()
{

}

void MapCase_3::tick()
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

