#include "MapCase_6.h"

MapCase_6::MapCase_6(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 6;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_6::~MapCase_6()
{

}

void MapCase_6::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("6번방 첫입장");

		for (int i = 0; i < 20; i++)
		{
			RocksMaker[i] = new Rocks;
		}

		RocksMaker[0]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 65), 13);
		RocksMaker[1]->CreateObject(_scene, Vec2(_position.x - 140, _position.y + 81), 2);
		RocksMaker[2]->CreateObject(_scene, Vec2(_position.x - 170, _position.y - 65), 13);
		RocksMaker[3]->CreateObject(_scene, Vec2(_position.x - 140, _position.y - 81), 6);

		RocksMaker[4]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 65), 13);
		RocksMaker[5]->CreateObject(_scene, Vec2(_position.x + 140, _position.y + 81), 1);
		RocksMaker[6]->CreateObject(_scene, Vec2(_position.x + 154, _position.y - 81), 14);
		RocksMaker[7]->CreateObject(_scene, Vec2(_position.x + 168, _position.y - 50), 3);
	}



	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

