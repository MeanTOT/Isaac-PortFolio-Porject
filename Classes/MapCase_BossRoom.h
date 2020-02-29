#pragma once
#include "MapBase.h"
#include "Dingle.h"
#include "TheSadOnion.h"
#include "BossLoadingScene_Dingle.h"
#include "TrapDoor.h"

class MapCase_BossRoom : public MapBase
{
private:
	EffectPoof* DingleMaker;
	altar* _altar;
	TheSadOnion* theSadOnion;
	TrapDoor* trapDoorMaker;
public:
	MapCase_BossRoom(Scene* scene, Vec2 position);
	~MapCase_BossRoom();

	bool clearOnDidFinish;

	void ClearOnDidFinish();

	void tick();
};
