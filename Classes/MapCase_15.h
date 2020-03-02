#pragma once
#include "MapBase.h"

class MapCase_15 : public MapBase
{
private:
	//EffectPoof* WallCreepMaker[2];
	Fire* FireMaker;
	Pit* PitMaker[12];
public:
	MapCase_15(Scene* scene, Vec2 position);
	~MapCase_15();

	void tick();
	void ClearOnDidFinish();
};
