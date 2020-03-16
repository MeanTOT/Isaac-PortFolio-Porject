#pragma once
#include "MapBase.h"

class MapCase_19 : public MapBase
{
private:
	EffectPoof* ChargerMaker[5];
	MushRoom* MushRoomMaker[4];
	Rocks_Cave* RocksCaveMaker[4];
	Bomb* BombMaker;
public:
	MapCase_19(Scene* scene, Vec2 position);
	~MapCase_19();

	void tick();
	void ClearOnDidFinish();
};
