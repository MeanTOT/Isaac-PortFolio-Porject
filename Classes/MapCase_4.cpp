#include "MapCase_4.h"

MapCase_4::MapCase_4(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorR(scene, position, NormalDoor);

	RoomNumber = 4;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_4::~MapCase_4()
{

}

void MapCase_4::tick()
{
	this->SetRoomNumber();
	this->CollisionToDoor();
	this->ClearCheck();
}

