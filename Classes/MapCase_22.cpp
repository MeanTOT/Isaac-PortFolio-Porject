#include "MapCase_22.h"

MapCase_22::MapCase_22(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorT(scene, position, BossRoomDoor);
	this->CreateDoorL(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 22;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 8; i++)
	{
		MushRoomMaker[i] = new MushRoom;
	}

	MushRoomMaker[0]->CreateObject(_scene, Vec2(_position.x - 32, _position.y - 32), 4);
	MushRoomMaker[1]->CreateObject(_scene, Vec2(_position.x - 32, _position.y + 32), 4);
	MushRoomMaker[2]->CreateObject(_scene, Vec2(_position.x + 32, _position.y - 32), 4);
	MushRoomMaker[3]->CreateObject(_scene, Vec2(_position.x + 32, _position.y + 32), 4);

	MushRoomMaker[4]->CreateObject(_scene, Vec2(_position.x - 32 * 3, _position.y), 4);
	MushRoomMaker[5]->CreateObject(_scene, Vec2(_position.x - 32 * 4, _position.y), 4);
	MushRoomMaker[6]->CreateObject(_scene, Vec2(_position.x + 32 * 3, _position.y), 4);
	MushRoomMaker[7]->CreateObject(_scene, Vec2(_position.x + 32 * 4, _position.y), 4);
}

MapCase_22::~MapCase_22()
{
}

void MapCase_22::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_22::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		BlubberMaker[0] = new EffectPoof(_scene, Vec2(_position.x, _position.y - 32 * 2), MonsterKind_Blubber);
		BlubberMaker[1] = new EffectPoof(_scene, Vec2(_position.x, _position.y + 32 * 2), MonsterKind_Blubber);

		log("22번방 첫입장");
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