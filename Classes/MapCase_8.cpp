#include "MapCase_8.h"

MapCase_8::MapCase_8(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorL(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);
	this->CreateDoorB(scene, position, TreasureDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 8;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_8::~MapCase_8()
{

}

void MapCase_8::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("8번방 첫입장");

		for (int i = 0; i < 13; i++)
		{
			RocksMaker[i] = new Rocks;
		}

		RocksMaker[0]->CreateObject(_scene, Vec2(_position.x, _position.y), 2);
		RocksMaker[1]->CreateObject(_scene, Vec2(_position.x - 64, _position.y), 1);
		RocksMaker[2]->CreateObject(_scene, Vec2(_position.x - 64 * 2, _position.y), 3);
		RocksMaker[3]->CreateObject(_scene, Vec2(_position.x + 64, _position.y), 2);
		RocksMaker[4]->CreateObject(_scene, Vec2(_position.x + 64 * 2, _position.y), 2);

		RocksMaker[5]->CreateObject(_scene, Vec2(_position.x - 32 * 3, _position.y + 32 * 2 - 10), 2);
		RocksMaker[6]->CreateObject(_scene, Vec2(_position.x - 32 * 5, _position.y + 32 * 2 - 10), 3);
		RocksMaker[7]->CreateObject(_scene, Vec2(_position.x + 32 * 3, _position.y + 32 * 2 - 10), 1);
		RocksMaker[8]->CreateObject(_scene, Vec2(_position.x + 32 * 5, _position.y + 32 * 2 - 10), 3);

		RocksMaker[9]->CreateObject(_scene, Vec2(_position.x - 32 * 3, _position.y - 32 * 2  + 10), 1);
		RocksMaker[10]->CreateObject(_scene, Vec2(_position.x - 32 * 5, _position.y - 32 * 2 + 10), 3);
		RocksMaker[11]->CreateObject(_scene, Vec2(_position.x + 32 * 3, _position.y - 32 * 2 + 10), 3);
		RocksMaker[12]->CreateObject(_scene, Vec2(_position.x + 32 * 5, _position.y - 32 * 2 + 10), 1);

		FlyMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 32 * 3, _position.y), MonsterKind_Fly);
		FlyMaker[1] = new EffectPoof(_scene, Vec2(_position.x - 32 * 2, _position.y + 32), MonsterKind_Fly);
		FlyMaker[2] = new EffectPoof(_scene, Vec2(_position.x - 32 * 4, _position.y + 32), MonsterKind_Fly);

		FlyMaker[3] = new EffectPoof(_scene, Vec2(_position.x + 32 * 3, _position.y), MonsterKind_Fly);
		FlyMaker[4] = new EffectPoof(_scene, Vec2(_position.x + 32 * 2, _position.y - 32), MonsterKind_Fly);
		FlyMaker[5] = new EffectPoof(_scene, Vec2(_position.x + 32 * 4, _position.y - 32), MonsterKind_Fly);

		PooterMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 32 * 3, _position.y - 32), MonsterKind_Pooter);
		PooterMaker[1] = new EffectPoof(_scene, Vec2(_position.x + 32 * 3, _position.y + 32), MonsterKind_Pooter);

		SMI->PlayDoorHeavyClose();
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

