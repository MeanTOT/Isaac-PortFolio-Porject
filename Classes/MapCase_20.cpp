#include "MapCase_20.h"

MapCase_20::MapCase_20(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorB(scene, position, NormalDoor);
	this->CreateDoorR(scene, position, NormalDoor);
	this->CreateDoorL(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 20;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;
}

MapCase_20::~MapCase_20()
{
}

void MapCase_20::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;

		BombMaker = new Bomb(_scene, _position);
	}
}

void MapCase_20::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		TumorMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 150, _position.y - 60), MonsterKind_Tumor);
		TumorMaker[1] = new EffectPoof(_scene, Vec2(_position.x + 150, _position.y + 60), MonsterKind_Tumor);

		log("20번방 첫입장");
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