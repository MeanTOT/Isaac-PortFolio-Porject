#include "MapCase_25.h"

MapCase_25::MapCase_25(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 25;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 16; i++)
	{
		Rocks_CaveMaker[i] = new Rocks_Cave;
	}

	Rocks_CaveMaker[0]->CreateObject(_scene, Vec2(_position.x, _position.y - 32), 1);
	Rocks_CaveMaker[1]->CreateObject(_scene, Vec2(_position.x - 32 * 2, _position.y - 32), 3);
	Rocks_CaveMaker[2]->CreateObject(_scene, Vec2(_position.x - 32 * 4, _position.y - 32), 2);
	Rocks_CaveMaker[3]->CreateObject(_scene, Vec2(_position.x, _position.y + 32), 1);
	Rocks_CaveMaker[4]->CreateObject(_scene, Vec2(_position.x + 32 * 2, _position.y + 32), 3);
	Rocks_CaveMaker[5]->CreateObject(_scene, Vec2(_position.x + 32 * 4, _position.y + 32), 3);
}

MapCase_25::~MapCase_25()
{
}

void MapCase_25::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_25::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		ClottyMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 128, _position.y), MonsterKind_Clotty);
		ClottyMaker[1] = new EffectPoof(_scene, Vec2(_position.x - 64, _position.y), MonsterKind_Clotty);
		ClottyMaker[2] = new EffectPoof(_scene, Vec2(_position.x + 64, _position.y), MonsterKind_Clotty);
		ClottyMaker[3] = new EffectPoof(_scene, Vec2(_position.x + 128, _position.y), MonsterKind_Clotty);

		log("25번방 첫입장");
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