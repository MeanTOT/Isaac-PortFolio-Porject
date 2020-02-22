#pragma once
#include "MapBase.h"

class MapCase_7 : public MapBase
{
private:
	Rocks* RocksMaker[15];
	EffectPoof* HorfMaker[4];
public:
	MapCase_7(Scene* scene, Vec2 position);
	~MapCase_7();

	void tick();
};
