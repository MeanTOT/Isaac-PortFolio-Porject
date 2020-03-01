#include "MapCase_14.h"

MapCase_14::MapCase_14(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorL(scene, position, NormalDoor);
	this->CreateDoorR(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 14;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 2; i++)
	{
		FireMaker[i] = new Fire;
	}

	for (int i = 0; i < 10; i++)
	{
		PitMaker[i] = new Pit;
	}

	FireMaker[0]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 80), 1);
	FireMaker[1]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 80), 1);

	PitMaker[0]->CreateObject(_scene, Vec2(_position.x, _position.y - 26 * 2), 2);
	PitMaker[1]->CreateObject(_scene, Vec2(_position.x - 40, _position.y - 26 * 2), 2);
	PitMaker[2]->CreateObject(_scene, Vec2(_position.x - 80, _position.y - 26 * 2), 2);
	PitMaker[3]->CreateObject(_scene, Vec2(_position.x - 120, _position.y - 26 * 2), 2);
	PitMaker[4]->CreateObject(_scene, Vec2(_position.x + 40, _position.y - 26 * 2), 2);
	PitMaker[5]->CreateObject(_scene, Vec2(_position.x + 80, _position.y - 26 * 2), 2);
	PitMaker[6]->CreateObject(_scene, Vec2(_position.x + 120, _position.y - 26 * 2), 2);
	PitMaker[7]->CreateObject(_scene, Vec2(_position.x + 160, _position.y - 26 * 2), 2);
	PitMaker[8]->CreateObject(_scene, Vec2(_position.x - 160, _position.y - 26 * 2), 2);
}

MapCase_14::~MapCase_14()
{
}

void MapCase_14::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_14::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		WallCreepMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 120, _position.y - 100), MonsterKind_WallCreep);
		WallCreepMaker[1] = new EffectPoof(_scene, Vec2(_position.x + 120, _position.y - 100), MonsterKind_WallCreep);

		log("14번방 첫입장");
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