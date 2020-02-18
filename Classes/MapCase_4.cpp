#include "MapCase_4.h"

MapCase_4::MapCase_4(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorR(scene, position);

	RoomNumber = 4;
	RoomClear = false;
	FirstEnter = false;
}

MapCase_4::~MapCase_4()
{

}

void MapCase_4::tick()
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

