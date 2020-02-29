#include "MapCase_BossRoom.h"

MapCase_BossRoom::MapCase_BossRoom(Scene * scene, Vec2 position)
{
	this->CreateBaseMentBossRoom(scene, position);
	this->CreateDoorL(scene, position, BossRoomDoor);

	_scene = scene;
	_position = position;
	RoomNumber = 10;
	RoomClear = false;
	FirstEnter = false;
	clearOnDidFinish = false;
}

MapCase_BossRoom::~MapCase_BossRoom()
{

}

void MapCase_BossRoom::ClearOnDidFinish()
{
	if (!clearOnDidFinish && !CI->camera->getNumberOfRunningActions())
	{
		trapDoorMaker = new TrapDoor;
		trapDoorMaker->CreateObject(_scene, Vec2(_position.x, _position.y + 50), 1);

		theSadOnion = new TheSadOnion(_scene, Vec2(_position.x, _position.y + 18 - 30));
		_altar = new altar;
		_altar->CreateObject(_scene, Vec2(_position.x,_position.y - 30), 1);
		AudioEngine::stopAll();
		SMI->PlayBossFightJingleOutro();

		clearOnDidFinish = true;
	}
}

void MapCase_BossRoom::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{

		Player->setIsLoadingScene(true);
		AudioEngine::stopAll();
		auto pScene = BossLoadingScene_Dingle::createScene();
		DI->pushScene(pScene);

		FirstEnter = true;

		DingleMaker = new EffectPoof(_scene, Vec2(_position), MonsterKind_Dingle);


		log("10[보스방]번방 첫입장");
	}

	if (Player->getRoomNumber() == RoomNumber)
	{
		if (RoomClear)
		{
			ClearOnDidFinish();
		}
	}


	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

