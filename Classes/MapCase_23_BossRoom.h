#pragma once
#include "MapBase.h"
#include "Dingle.h"
#include "TheSadOnion.h"
#include "BossLoadingScene_MeGaMaw.h"
#include "TrapDoor.h"

class MapCase_23_BossRoom : public MapBase
{
private:
	EffectPoof* MagaMawMaker;
	altar* _altar;
	TheSadOnion* theSadOnion;
	TrapDoor* trapDoorMaker;
public:
	MapCase_23_BossRoom(Scene* scene, Vec2 position);
	~MapCase_23_BossRoom();

	void tick();
	void ClearOnDidFinish();
};
