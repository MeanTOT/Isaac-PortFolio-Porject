#include "MapCase_13.h"

MapCase_13::MapCase_13(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorL(scene, position, NormalDoor);
	this->CreateDoorR(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 13;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 10; i++)
	{
		RocksMaker[i] = new Rocks;
	}

	RocksMaker[0]->CreateObject(_scene, Vec2(_position.x - 32, _position.y - 32 * 2), 1);
	RocksMaker[1]->CreateObject(_scene, Vec2(_position.x + 32, _position.y + 32 * 2), 3);
	RocksMaker[2]->CreateObject(_scene, Vec2(_position.x - 32 * 3, _position.y - 32 * 2), 2);
	RocksMaker[3]->CreateObject(_scene, Vec2(_position.x + 32 * 3, _position.y + 32 * 2), 2);
	RocksMaker[4]->CreateObject(_scene, Vec2(_position.x - 32 * 5, _position.y - 32), 7);
	RocksMaker[5]->CreateObject(_scene, Vec2(_position.x + 32 * 5, _position.y + 32), 1);

	RocksMaker[6]->CreateObject(_scene, Vec2(_position.x + 32 * 3, _position.y - 32 * 2), 2);
	RocksMaker[7]->CreateObject(_scene, Vec2(_position.x - 32 * 3, _position.y + 32 * 2), 1);
}

MapCase_13::~MapCase_13()
{
}

void MapCase_13::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_13::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		BoomFlyMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 160, _position.y - 70), MonsterKind_BoomFly);
		BoomFlyMaker[1] = new EffectPoof(_scene, Vec2(_position.x - 160, _position.y + 70), MonsterKind_BoomFly);
		BoomFlyMaker[2] = new EffectPoof(_scene, Vec2(_position.x + 160, _position.y - 70), MonsterKind_BoomFly);
		BoomFlyMaker[3] = new EffectPoof(_scene, Vec2(_position.x + 160, _position.y + 70), MonsterKind_BoomFly);

		log("13번방 첫입장");
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