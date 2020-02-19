#include "MapCase_5.h"

MapCase_5::MapCase_5(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorB(scene, position, NormalDoor);

	RoomNumber = 5;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_5::~MapCase_5()
{

}

void MapCase_5::tick()
{
	this->SetRoomNumber();
	this->CollisionToDoor();
	this->ClearCheck();
}

