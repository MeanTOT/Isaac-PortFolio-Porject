#include "MapCase_3.h"

MapCase_3::MapCase_3(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorL(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 3;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_3::~MapCase_3()
{

}

void MapCase_3::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("3번방 첫입장");

		for (int i = 0; i < 6; i++)
		{
			PoopMaker[i] = new Poop;
		}
		PoopMaker[0]->CreateObject(_scene, Vec2(_position.x - 64, _position.y - 32), 1);
		PoopMaker[1]->CreateObject(_scene, Vec2(_position.x - 64, _position.y), 1);
		PoopMaker[2]->CreateObject(_scene, Vec2(_position.x - 64, _position.y + 32), 1);
		PoopMaker[3]->CreateObject(_scene, Vec2(_position.x + 64, _position.y - 32), 1);
		PoopMaker[4]->CreateObject(_scene, Vec2(_position.x + 64, _position.y), 1);
		PoopMaker[5]->CreateObject(_scene, Vec2(_position.x + 64, _position.y + 32), 1);

		FlyMaker[0] = new EffectPoof(_scene, Vec2(_position.x,_position.y + 32), MonsterKind_Fly);
		FlyMaker[1] = new EffectPoof(_scene, Vec2(_position.x,_position.y), MonsterKind_Fly);
		FlyMaker[2] = new EffectPoof(_scene, Vec2(_position.x,_position.y - 32), MonsterKind_Fly);
	}


	this->SetRoomNumber();
	this->CollisionToDoor();
	this->ClearCheck();
}

