#pragma once
#include "MapBase.h"

class MapCase_14 : public MapBase
{
private:
	EffectPoof* WallCreepMaker[2];
	Fire* FireMaker[2];
	Pit* PitMaker[10];
public:
	MapCase_14(Scene* scene, Vec2 position);
	~MapCase_14();

	void tick();
	void ClearOnDidFinish();
};