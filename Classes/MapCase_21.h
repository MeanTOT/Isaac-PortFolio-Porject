#pragma once
#include "MapBase.h"

class MapCase_21 : public MapBase
{
private:
	EffectPoof* BoneyMaker[4];
	Rocks* RocksMaker[4];
public:
	MapCase_21(Scene* scene, Vec2 position);
	~MapCase_21();

	void tick();
	void ClearOnDidFinish();
};
