#include "MapCase_26.h"

MapCase_26::MapCase_26(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorB(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 26;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 16; i++)
	{
		RocksMaker[i] = new Rocks;
	}

	RocksMaker[0]->CreateObject(_scene, Vec2(_position.x - 32, _position.y + 80), 4);
	RocksMaker[1]->CreateObject(_scene, Vec2(_position.x - 32, _position.y + 80 - 32), 4);
	RocksMaker[2]->CreateObject(_scene, Vec2(_position.x - 32, _position.y + 80  - 64), 4);
	RocksMaker[3]->CreateObject(_scene, Vec2(_position.x + 32, _position.y + 80), 4);
	RocksMaker[4]->CreateObject(_scene, Vec2(_position.x + 32, _position.y + 80 - 32), 4);
	RocksMaker[5]->CreateObject(_scene, Vec2(_position.x + 32, _position.y + 80 - 64), 4);

	LocksMaker = new Locks;

	LocksMaker->CreateObject(_scene, Vec2(_position.x, _position.y + 80 - 64), 0);
}

MapCase_26::~MapCase_26()
{
}

void MapCase_26::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_26::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		pillMaker = new Pill(_scene, Vec2(_position.x, _position.y + 80));

		log("26번방 첫입장");
	}

	if (Player->getRoomNumber() == RoomNumber && FirstEnter == true)
	{
		if (RoomClear && clearOnDidFinishCount <= 0)
		{
			ClearOnDidFinish();
		}
	}

	this->ClearOnDidFinishCount();
	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}