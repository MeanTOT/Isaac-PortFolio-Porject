#pragma once
#include "MapBase.h"

class MapCase_8 : public MapBase
{
private:
	Rocks* RocksMaker[13];
	EffectPoof* FlyMaker[6];
	EffectPoof* PooterMaker[2];
public:
	MapCase_8(Scene* scene, Vec2 position);
	~MapCase_8();

	void tick();
};
