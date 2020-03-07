#include "MapCase_5.h"

MapCase_5::MapCase_5(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorR(scene, position, BossRoomDoor);
	this->CreateDoorL(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 5;
	RoomClear = true;
	FirstEnter = false;

	for (int i = 0; i < 17; i++)
	{
		RocksMaker[i] = new Rocks;
	}

	RocksMaker[0]->CreateObject(_scene, Vec2(_position.x - 160, _position.y - 64), 1);
	RocksMaker[1]->CreateObject(_scene, Vec2(_position.x - 96, _position.y - 64), 2);
	RocksMaker[2]->CreateObject(_scene, Vec2(_position.x - 32, _position.y - 64), 2);
	RocksMaker[3]->CreateObject(_scene, Vec2(_position.x + 32, _position.y - 64), 2);
	RocksMaker[4]->CreateObject(_scene, Vec2(_position.x + 96, _position.y - 64), 1);
	RocksMaker[5]->CreateObject(_scene, Vec2(_position.x + 160, _position.y - 64), 5);
	RocksMaker[6]->CreateObject(_scene, Vec2(_position.x - 128, _position.y), 1);
	RocksMaker[7]->CreateObject(_scene, Vec2(_position.x - 64, _position.y), 1);
	RocksMaker[8]->CreateObject(_scene, Vec2(_position.x, _position.y), 1);
	RocksMaker[9]->CreateObject(_scene, Vec2(_position.x + 64, _position.y), 2);
	RocksMaker[10]->CreateObject(_scene, Vec2(_position.x + 128, _position.y), 1);
	RocksMaker[11]->CreateObject(_scene, Vec2(_position.x - 160, _position.y + 64), 3);
	RocksMaker[12]->CreateObject(_scene, Vec2(_position.x - 96, _position.y + 64), 1);
	RocksMaker[13]->CreateObject(_scene, Vec2(_position.x - 32, _position.y + 64), 2);
	RocksMaker[14]->CreateObject(_scene, Vec2(_position.x + 32, _position.y + 64), 1);
	RocksMaker[15]->CreateObject(_scene, Vec2(_position.x + 96, _position.y + 64), 2);
	RocksMaker[16]->CreateObject(_scene, Vec2(_position.x + 160, _position.y + 64), 1);
}

MapCase_5::~MapCase_5()
{

}

void MapCase_5::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("5번방 첫입장");
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}
