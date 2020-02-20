#include "MapCase_4.h"

MapCase_4::MapCase_4(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorR(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 4;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_4::~MapCase_4()
{

}

void MapCase_4::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("4번방 첫입장");
		
		for (int i = 0; i < 4; i++)
		{
			PoopMaker[i] = new Poop;
		}

		PoopMaker[0]->CreateObject(_scene, Vec2(_position.x - 32, _position.y), 1);
		PoopMaker[1]->CreateObject(_scene, Vec2(_position.x + 32, _position.y), 1);
		PoopMaker[2]->CreateObject(_scene, Vec2(_position.x, _position.y + 32), 1);
		PoopMaker[3]->CreateObject(_scene, Vec2(_position.x, _position.y - 32), 1);

		DipMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 170, _position.y + 80), MonsterKind_Dip);
		DipMaker[1] = new EffectPoof(_scene, Vec2(_position.x + 170, _position.y + 80), MonsterKind_Dip);
		DipMaker[2] = new EffectPoof(_scene, Vec2(_position.x - 170, _position.y - 80), MonsterKind_Dip);
		DipMaker[3] = new EffectPoof(_scene, Vec2(_position.x + 170, _position.y - 80), MonsterKind_Dip);
	}

	this->SetRoomNumber();
	this->CollisionToDoor();
	this->ClearCheck();
}

