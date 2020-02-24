#pragma once
#include "MapBase.h"
#include "Dingle.h"

class MapCase_BossRoom : public MapBase
{
private:
	Dingle* dingleMaker;
public:
	MapCase_BossRoom(Scene* scene, Vec2 position);
	~MapCase_BossRoom();

	void tick();
};
