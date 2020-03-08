#include "MapCase_24_ShopRoom.h"

MapCase_24_ShopRoom::MapCase_24_ShopRoom(Scene* scene, Vec2 position)
{
	this->CreateShopRoom(scene, position);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 24;
	RoomClear = true;
	FirstEnter = false;

	shopMasgerMaker = new ShopMaster;
	shopMasgerMaker->CreateObject(_scene, Vec2(_position.x, _position.y + 50), 0);

	fireMaker[0] = new Fire;
	fireMaker[1] = new Fire;

	fireMaker[0]->CreateObject(_scene, Vec2(_position.x - 140, _position.y + 50), 1);
	fireMaker[1]->CreateObject(_scene, Vec2(_position.x + 140, _position.y + 50), 1);

	for (int i = 0; i < 10; i++)
	{
		ShopPriceNumberMaker[i] = new ShopPriceNumber;
	}

	ShopPriceNumberMaker[0]->CreateObject(_scene, Vec2(_position.x - 70, _position.y - 50), 6);
	ShopPriceNumberMaker[1]->CreateObject(_scene, Vec2(_position.x - 60, _position.y - 50), 12);

	ShopPriceNumberMaker[2]->CreateObject(_scene, Vec2(_position.x - 15, _position.y - 50), 2);
	ShopPriceNumberMaker[3]->CreateObject(_scene, Vec2(_position.x, _position.y - 50), 6);
	ShopPriceNumberMaker[4]->CreateObject(_scene, Vec2(_position.x + 10, _position.y - 50), 12);

	ShopPriceNumberMaker[5]->CreateObject(_scene, Vec2(_position.x + 70, _position.y - 50), 6);
	ShopPriceNumberMaker[6]->CreateObject(_scene, Vec2(_position.x + 80, _position.y - 50), 12);

	shopHeartMaker = new ShopHeart(_scene, Vec2(_position.x - 66, _position.y - 35));
	shopKeyMaker = new ShopKey(_scene, Vec2(_position.x + 74, _position.y - 35));
	shopItem_BloodOfTheMarTyrMaker = new ShopItem_BloodOfTheMarTyr(_scene, Vec2(_position.x, _position.y - 35));
}

MapCase_24_ShopRoom::~MapCase_24_ShopRoom()
{
}

void MapCase_24_ShopRoom::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("24번방 첫입장");
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}