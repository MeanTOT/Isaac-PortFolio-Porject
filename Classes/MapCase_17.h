#pragma once
#include "MapBase.h"
#include "Heart.h"

class MapCase_17 : public MapBase
{
private:
	EffectPoof* BoneyMaker[2];
	Rocks* RockMaker[2];
	Pit* PitMaker[12];
	Heart* HeartMaker;
public:
	MapCase_17(Scene* scene, Vec2 position);
	~MapCase_17();

	void tick();
	void ClearOnDidFinish();
};
