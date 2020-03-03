#include "MapCase_12.h"

MapCase_12::MapCase_12(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorL(scene, position, TreasureNoneKeyDoor);
	this->CreateDoorR(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 12;
	RoomClear = true;
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

MapCase_12::~MapCase_12()
{
}

void MapCase_12::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		coinMaker = new Coin(_scene, _position);

		clearOnDidFinish = true;
	}
}

void MapCase_12::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		TumorMaker = new EffectPoof(_scene, _position, MonsterKind_Tumor);

		log("12번방 첫입장");
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