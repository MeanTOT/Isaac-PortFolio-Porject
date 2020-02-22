#include "MapCase_7.h"

MapCase_7::MapCase_7(Scene * scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorB(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 7;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_7::~MapCase_7()
{

}

void MapCase_7::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		log("7번방 첫입장");

		for (int i = 0; i < 15; i++)
		{
			RocksMaker[i] = new Rocks;
		}

		RocksMaker[0]->CreateObject(_scene, Vec2(_position.x, _position.y), 2);
		RocksMaker[1]->CreateObject(_scene, Vec2(_position.x - 170, _position.y - 80), 1);
		RocksMaker[2]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 80), 3);
		RocksMaker[3]->CreateObject(_scene, Vec2(RocksMaker[2]->ObjectSprite->getPosition().x + 32, RocksMaker[2]->ObjectSprite->getPosition().y - 32), 1);
		RocksMaker[4]->CreateObject(_scene, Vec2(RocksMaker[1]->ObjectSprite->getPosition().x + 32, RocksMaker[1]->ObjectSprite->getPosition().y + 32), 3);
		RocksMaker[5]->CreateObject(_scene, Vec2(_position.x + 170, _position.y - 80), 1);
		RocksMaker[6]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 80), 3);
		RocksMaker[7]->CreateObject(_scene, Vec2(RocksMaker[6]->ObjectSprite->getPosition().x - 32, RocksMaker[6]->ObjectSprite->getPosition().y - 32), 3);
		RocksMaker[8]->CreateObject(_scene, Vec2(RocksMaker[5]->ObjectSprite->getPosition().x - 32, RocksMaker[5]->ObjectSprite->getPosition().y + 32), 1);

		HorfMaker[0] = new EffectPoof(_scene, Vec2(_position.x, _position.y + 32), MonsterKind_Horf);
		HorfMaker[1] = new EffectPoof(_scene, Vec2(_position.x, _position.y - 32), MonsterKind_Horf);
		HorfMaker[2] = new EffectPoof(_scene, Vec2(_position.x - 32, _position.y), MonsterKind_Horf);
		HorfMaker[3] = new EffectPoof(_scene, Vec2(_position.x + 32, _position.y), MonsterKind_Horf);
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

