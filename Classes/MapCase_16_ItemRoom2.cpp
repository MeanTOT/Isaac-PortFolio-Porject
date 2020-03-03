#include "MapCase_16_ItemRoom2.h"

MapCase_16_ItemRoom2::MapCase_16_ItemRoom2(Scene * scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorR(scene, position, TreasureNoneKeyDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 16;
	RoomClear = true;
	FirstEnter = false;


	for (int i = 0; i < 8; i++)
	{
		RockMaker[i] = new Rocks;
	}


	_magicMushRoom = new MagicMushRoom(_scene, Vec2(_position.x, _position.y + 18));
	_altar = new altar;

	RockMaker[0]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 80), 15);
	RockMaker[1]->CreateObject(_scene, Vec2(_position.x - 170 + 64, _position.y + 80), 15);
	RockMaker[2]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 80), 15);
	RockMaker[3]->CreateObject(_scene, Vec2(_position.x + 170 - 64, _position.y + 80), 15);

	RockMaker[4]->CreateObject(_scene, Vec2(_position.x - 170, _position.y - 80), 15);
	RockMaker[5]->CreateObject(_scene, Vec2(_position.x - 170 + 64, _position.y - 80), 15);
	RockMaker[6]->CreateObject(_scene, Vec2(_position.x + 170, _position.y - 80), 15);
	RockMaker[7]->CreateObject(_scene, Vec2(_position.x + 170 - 64, _position.y - 80), 15);

	_altar->CreateObject(_scene, _position, 1);
}

MapCase_16_ItemRoom2::~MapCase_16_ItemRoom2()
{

}

void MapCase_16_ItemRoom2::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;


		log("16[아이템방]번방 첫입장");
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

