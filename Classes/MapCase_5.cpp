#include "MapCase_5.h"

MapCase_5::MapCase_5(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorB(scene, position);

	RoomNumber = 5;
	RoomClear = false;
}

MapCase_5::~MapCase_5()
{

}

void MapCase_5::tick()
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

