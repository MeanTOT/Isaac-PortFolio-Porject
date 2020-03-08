#include "MapCase_21.h"

MapCase_21::MapCase_21(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorT(scene, position, NormalDoor);
	this->CreateDoorB(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 21;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 4; i++)
	{
		RocksMaker[i] = new Rocks;
	}

	RocksMaker[0]->CreateObject(_scene, Vec2(_position.x - 170, _position.y - 80), 4);
	RocksMaker[1]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 80), 4);
	RocksMaker[2]->CreateObject(_scene, Vec2(_position.x + 170, _position.y - 80), 4);
	RocksMaker[3]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 80), 4);
}

MapCase_21::~MapCase_21()
{
}

void MapCase_21::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_21::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		BoneyMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 32, _position.y - 32), MonsterKind_Boney);
		BoneyMaker[1] = new EffectPoof(_scene, Vec2(_position.x - 32, _position.y + 32), MonsterKind_Boney);
		BoneyMaker[2] = new EffectPoof(_scene, Vec2(_position.x + 32, _position.y - 32), MonsterKind_Boney);
		BoneyMaker[3] = new EffectPoof(_scene, Vec2(_position.x + 32, _position.y + 32), MonsterKind_Boney);

		log("21번방 첫입장");
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