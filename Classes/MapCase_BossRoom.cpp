#include "MapCase_BossRoom.h"

MapCase_BossRoom::MapCase_BossRoom(Scene * scene, Vec2 position)
{
	this->CreateBaseMentBossRoom(scene, position);
	this->CreateDoorL(scene, position, BossRoomDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 10;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_BossRoom::~MapCase_BossRoom()
{

}

void MapCase_BossRoom::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		dingleMaker = new Dingle(_scene, _position);

		log("10[보스방]번방 첫입장");
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

