#include "MapCase_3.h"

MapCase_3::MapCase_3(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateNormalDoorL(scene, position);

	_scene = scene;
	_position = position;
	RoomNumber = 3;
	RoomClear = false;
	FirstEnter = false;
}

MapCase_3::~MapCase_3()
{

}

void MapCase_3::tick()
{
	if (mapLT->getPosition().x - mapLT->getContentSize().width < Player->getIsaacBody()->getPosition().x &&
		mapLT->getPosition().x + mapLT->getContentSize().width > Player->getIsaacBody()->getPosition().x &&
		mapLT->getPosition().y - mapLT->getContentSize().height < Player->getIsaacBody()->getPosition().y &&
		mapLT->getPosition().y + mapLT->getContentSize().height > Player->getIsaacBody()->getPosition().y)
	{
		Player->setRoomNumber(RoomNumber);
	}

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
	}


	
	this->CollisionToDoor();
}

