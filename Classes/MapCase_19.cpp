#include "MapCase_19.h"

MapCase_19::MapCase_19(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorB(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 19;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 4; i++)
	{
		MushRoomMaker[i] = new MushRoom;
		RocksCaveMaker[i] = new Rocks_Cave;
	}

	MushRoomMaker[0]->CreateObject(_scene, Vec2(_position.x - 32, _position.y), 1);
	MushRoomMaker[1]->CreateObject(_scene, Vec2(_position.x - 32 * 3, _position.y - 32 * 2), 2);
	MushRoomMaker[2]->CreateObject(_scene, Vec2(_position.x + 32 * 2, _position.y), 2);
	MushRoomMaker[3]->CreateObject(_scene, Vec2(_position.x + 32 * 3, _position.y - 32 * 2), 3);

	RocksCaveMaker[0]->CreateObject(_scene, Vec2(_position.x + 32, _position.y - 32), 1);
	RocksCaveMaker[1]->CreateObject(_scene, Vec2(_position.x + 32 * 4, _position.y + 32 ), 2);
	RocksCaveMaker[2]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 80), 2);
	RocksCaveMaker[3]->CreateObject(_scene, Vec2(_position.x - 170, _position.y - 80), 3);
}

MapCase_19::~MapCase_19()
{
}

void MapCase_19::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_19::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		BombMaker = new Bomb(_scene, _position);

		log("19번방 첫입장");
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