#include "MapCase_18.h"

MapCase_18::MapCase_18(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorB(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 18;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;

	for (int i = 0; i < 12; i++)
	{
		MushRoomMaker[i] = new MushRoom;
	}

	MushRoomMaker[0]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 80), 1);
	MushRoomMaker[1]->CreateObject(_scene, Vec2(_position.x - 170, _position.y + 80 -  32), 2);
	MushRoomMaker[2]->CreateObject(_scene, Vec2(_position.x - 170 + 32, _position.y + 80), 2);

	MushRoomMaker[3]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 80), 3);
	MushRoomMaker[4]->CreateObject(_scene, Vec2(_position.x + 170, _position.y + 80 - 32), 2);
	MushRoomMaker[5]->CreateObject(_scene, Vec2(_position.x + 170 - 32, _position.y + 80), 1);

	MushRoomMaker[6]->CreateObject(_scene, Vec2(_position.x - 170, _position.y - 80), 2);
	MushRoomMaker[7]->CreateObject(_scene, Vec2(_position.x - 170, _position.y -  + 32), 2);
	MushRoomMaker[8]->CreateObject(_scene, Vec2(_position.x - 170 + 32, _position.y - 80), 1);

	MushRoomMaker[9]->CreateObject(_scene, Vec2(_position.x  + 170, _position.y - 80), 1);
	MushRoomMaker[10]->CreateObject(_scene, Vec2(_position.x + 170, _position.y - 80 + 32), 3);
	MushRoomMaker[11]->CreateObject(_scene, Vec2(_position.x + 170 - 32, _position.y - 80), 2);

}

MapCase_18::~MapCase_18()
{
}

void MapCase_18::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{

		clearOnDidFinish = true;
	}
}

void MapCase_18::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		CoinMaker = new Coin(_scene, _position);

		FlyMaker[0] = new EffectPoof(_scene, Vec2(_position.x - 32, _position.y - 32), MonsterKind_Fly);
		FlyMaker[1] = new EffectPoof(_scene, Vec2(_position.x, _position.y - 32), MonsterKind_Fly);
		FlyMaker[2] = new EffectPoof(_scene, Vec2(_position.x + 32, _position.y - 32), MonsterKind_Fly);
		FlyMaker[3] = new EffectPoof(_scene, Vec2(_position.x - 32, _position.y), MonsterKind_Fly);
		FlyMaker[4] = new EffectPoof(_scene, Vec2(_position.x + 32, _position.y), MonsterKind_Fly);
		FlyMaker[5] = new EffectPoof(_scene, Vec2(_position.x - 32, _position.y + 32), MonsterKind_Fly);
		FlyMaker[6] = new EffectPoof(_scene, Vec2(_position.x, _position.y + 32), MonsterKind_Fly);
		FlyMaker[7] = new EffectPoof(_scene, Vec2(_position.x + 32, _position.y + 32), MonsterKind_Fly);

		log("18번방 첫입장");
	}

	if (Player->getRoomNumber() == RoomNumber && FirstEnter == true)
	{
		if (RoomClear && clearOnDidFinishCount <= 0)
		{
			ClearOnDidFinish();
		}
	}

	this->ClearOnDidFinishCount();
	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}