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

		for (int i = 0; i < 15; i++)
		{
			RocksMaker[i] = new Rocks;
		}
		for (int i = 0; i < 8; i++)
		{
			FireMaker[i] = new Fire;
		}

		RocksMaker[0]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 65), 13);
		RocksMaker[1]->CreateObject(_scene, Vec2(_position.x - 140, _position.y + 81), 2);
		RocksMaker[2]->CreateObject(_scene, Vec2(_position.x - 170, _position.y - 65), 13);
		RocksMaker[3]->CreateObject(_scene, Vec2(_position.x - 140, _position.y - 81), 6);

		RocksMaker[4]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 65), 13);
		RocksMaker[5]->CreateObject(_scene, Vec2(_position.x + 140, _position.y + 81), 1);
		RocksMaker[6]->CreateObject(_scene, Vec2(_position.x + 154, _position.y - 81), 14);
		RocksMaker[7]->CreateObject(_scene, Vec2(_position.x + 168, _position.y - 50), 3);
		
		RocksMaker[8]->CreateObject(_scene, Vec2(_position.x + 16, _position.y), 14);
		RocksMaker[9]->CreateObject(_scene, Vec2(_position.x + 32, _position.y + 32), 2);
		RocksMaker[10]->CreateObject(_scene, Vec2(_position.x + 64, _position.y), 1);
		RocksMaker[11]->CreateObject(_scene, Vec2(_position.x + 32, _position.y - 32), 3);
		RocksMaker[12]->CreateObject(_scene, Vec2(_position.x - 32, _position.y + 16), 13);
		RocksMaker[13]->CreateObject(_scene, Vec2(_position.x - 32, _position.y - 32), 2);
		RocksMaker[14]->CreateObject(_scene, Vec2(_position.x - 64, _position.y), 1);





		FireMaker[0]->CreateObject(_scene, Vec2(_position.x - 140, _position.y - 55), 1);
		FireMaker[1]->CreateObject(_scene, Vec2(_position.x + 140, _position.y - 55), 1);
		FireMaker[2]->CreateObject(_scene, Vec2(_position.x - 140, _position.y + 55), 1);
		FireMaker[3]->CreateObject(_scene, Vec2(_position.x + 140, _position.y + 55), 1);

		FireMaker[4]->CreateObject(_scene, Vec2(_position.x,_position.y - 32), 1);
		FireMaker[5]->CreateObject(_scene, Vec2(_position.x, _position.y + 32), 1);
		FireMaker[6]->CreateObject(_scene, Vec2(_position.x - 96, _position.y), 1);
		FireMaker[7]->CreateObject(_scene, Vec2(_position.x + 96, _position.y), 1);
	
	}



	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

