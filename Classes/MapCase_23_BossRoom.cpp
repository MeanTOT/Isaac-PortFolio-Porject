#include "MapCase_23_BossRoom.h"

MapCase_23_BossRoom::MapCase_23_BossRoom(Scene* scene, Vec2 position)
{
	this->CreateCavesRoom(scene, position);
	this->CreateDoorB(scene, position, BossRoomDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 23;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;
}

MapCase_23_BossRoom::~MapCase_23_BossRoom()
{
}

void MapCase_23_BossRoom::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		trapDoorMaker = new TrapDoor;
		trapDoorMaker->CreateObject(_scene, Vec2(_position.x, _position.y + 50), 1);

		AudioEngine::stopAll();
		SMI->PlayBossFightJingleOutro();

		clearOnDidFinish = true;
	}
}

void MapCase_23_BossRoom::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		Player->setIsLoadingScene(true);
		AudioEngine::stopAll();
		auto pScene = BossLoadingScene_MeGaMaw::createScene();
		DI->pushScene(pScene);

		FirstEnter = true;

		MagaMawMaker = new EffectPoof(_scene, Vec2(_position.x , _position.y), MonsterKind_MegaMaw);

		log("23번방 첫입장");
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