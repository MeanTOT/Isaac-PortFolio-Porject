#include "MapCase_17.h"

MapCase_17::MapCase_17(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorB(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 17;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 12; i++)
	{
		PitMaker[i] = new Pit;
	}

	RockMaker[0] = new Rocks;
	RockMaker[1] = new Rocks;

	RockMaker[0]->CreateObject(_scene, Vec2(_position.x + 32 * 2, _position.y), 2);
	RockMaker[1]->CreateObject(_scene, Vec2(_position.x - 32 * 2, _position.y), 2);

	PitMaker[0]->CreateObject(_scene, Vec2(_position.x - 160, _position.y + 26), 2);
	PitMaker[1]->CreateObject(_scene, Vec2(_position.x - 120, _position.y + 26), 2);
	PitMaker[2]->CreateObject(_scene, Vec2(_position.x - 80, _position.y + 26), 2);
	PitMaker[3]->CreateObject(_scene, Vec2(_position.x - 160, _position.y - 26), 2);
	PitMaker[4]->CreateObject(_scene, Vec2(_position.x - 120, _position.y - 26), 2);
	PitMaker[5]->CreateObject(_scene, Vec2(_position.x - 80, _position.y - 26), 2);

	PitMaker[6]->CreateObject(_scene, Vec2(_position.x + 160, _position.y + 26), 2);
	PitMaker[7]->CreateObject(_scene, Vec2(_position.x + 120, _position.y + 26), 2);
	PitMaker[8]->CreateObject(_scene, Vec2(_position.x + 80, _position.y + 26), 2);
	PitMaker[9]->CreateObject(_scene, Vec2(_position.x + 160, _position.y - 26), 2);
	PitMaker[10]->CreateObject(_scene, Vec2(_position.x + 120, _position.y - 26), 2);
	PitMaker[11]->CreateObject(_scene, Vec2(_position.x + 80, _position.y - 26), 2);

}

MapCase_17::~MapCase_17()
{
}

void MapCase_17::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		HeartMaker = new Heart(_scene,_position);

		clearOnDidFinish = true;
	}
}

void MapCase_17::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		BoneyMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 100, _position.y), MonsterKind_Boney);
		BoneyMaker[1] = new EffectPoof(_scene, Vec2(_position.x + 100, _position.y), MonsterKind_Boney);

		log("17번방 첫입장");
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