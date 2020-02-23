#include "MapCase_ItemRoom1.h"

MapCase_ItemRoom1::MapCase_ItemRoom1(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorL(scene, position, TreasureNoneKeyDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 9;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_ItemRoom1::~MapCase_ItemRoom1()
{

}

void MapCase_ItemRoom1::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		altar = Sprite::create("ITEMS/altar.png");
		altar->setPosition(_position);
		_scene->addChild(altar);

		log("9[아이템방]번방 첫입장");
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

