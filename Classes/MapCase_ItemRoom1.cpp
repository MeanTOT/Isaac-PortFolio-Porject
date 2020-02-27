#include "MapCase_ItemRoom1.h"

MapCase_ItemRoom1::MapCase_ItemRoom1(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorT(scene, position, TreasureNoneKeyDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 9;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_ItemRoom1::~MapCase_ItemRoom1()
{

}

void MapCase_ItemRoom1::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;
		
		PoopMaker[0] = new Poop;
		PoopMaker[1] = new Poop;
		_stigmata = new Stigmata(_scene, Vec2(_position.x, _position.y + 18));
		_altar = new altar;
		
		PoopMaker[0]->CreateObject(_scene, Vec2(_position.x - 32, _position.y), 1);
		PoopMaker[1]->CreateObject(_scene, Vec2(_position.x + 32, _position.y), 1);

		_altar->CreateObject(_scene, _position, 1);

		log("9[아이템방]번방 첫입장");
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

