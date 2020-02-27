#include "MapCase_1.h"

MapCase_1::MapCase_1(Scene* scene, Vec2 position)
{

	controlsImage = Sprite::create("MapImage/controls.png");
	controlsImage->setPosition(position);
	scene->addChild(controlsImage, BackGroundZoder + 1);

	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorL(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);
	this->CreateDoorB(scene, position, NormalDoor);

	RoomNumber = 1;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_1::~MapCase_1()
{
}

void MapCase_1::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("1번방 첫입장");
	}

	
	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();	
}
