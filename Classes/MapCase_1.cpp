#include "MapCase_1.h"

MapCase_1::MapCase_1(Scene* scene, Vec2 position)
{
	controlsImage = Sprite::create("MapImage/controls.png");
	controlsImage->setPosition(position);
	scene->addChild(controlsImage, -99998);

	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorR(scene, position);
	this->CreateNormalDoorL(scene, position);
	this->CreateNormalDoorT(scene, position);
	this->CreateNormalDoorB(scene, position);

	RoomNumber = 1;
	RoomClear = false;
	FirstEnter = false;
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
