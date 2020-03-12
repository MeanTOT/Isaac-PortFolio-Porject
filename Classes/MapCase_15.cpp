#include "MapCase_15.h"

MapCase_15::MapCase_15(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorT(scene, position, NormalDoor);
	this->CreateDoorB(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 15;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	FireMaker = new Fire;

	for (int i = 0; i < 12; i++)
	{
		PitMaker[i] = new Pit;
	}

	FireMaker->CreateObject(_scene, _position, 1);

	PitMaker[0]->CreateObject(_scene, Vec2(_position.x - 160, _position.y + 26 * 3), 2);
	PitMaker[1]->CreateObject(_scene, Vec2(_position.x - 120, _position.y + 26 * 3), 2);
	PitMaker[2]->CreateObject(_scene, Vec2(_position.x - 80,  _position.y + 26 * 3), 2);
	PitMaker[3]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 26 * 2), 1);
	PitMaker[4]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 26 * 1), 1);
	PitMaker[5]->CreateObject(_scene, Vec2(_position.x - 170, _position.y), 3);

	PitMaker[6]->CreateObject(_scene, Vec2(_position.x + 100, _position.y - 26 * 3), 2);
	PitMaker[7]->CreateObject(_scene, Vec2(_position.x + 140, _position.y - 26 * 3), 2);
	PitMaker[8]->CreateObject(_scene, Vec2(_position.x + 170, _position.y), 4);

	PitMaker[9]->CreateObject(_scene, Vec2(_position.x + 170, _position.y - 26 * 3), 5);
	PitMaker[10]->CreateObject(_scene, Vec2(_position.x + 170, _position.y - 26 * 2), 5);
	PitMaker[11]->CreateObject(_scene, Vec2(_position.x + 170, _position.y - 26 * 1), 5);

}

MapCase_15::~MapCase_15()
{
}

void MapCase_15::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		clearOnDidFinish = true;
	}
}

void MapCase_15::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		NestMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 140, _position.y - 50), MonsterKind_Nest);
		NestMaker[1] = new EffectPoof(_scene, Vec2(_position.x + 140, _position.y + 50), MonsterKind_Nest);

		log("15번방 첫입장");
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