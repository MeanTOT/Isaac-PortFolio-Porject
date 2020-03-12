#pragma once
#include "MapBase.h"

class MapCase_25 : public MapBase
{
private:
	EffectPoof* ClottyMaker[4];
	Rocks_Cave* Rocks_CaveMaker[16];
public:
	MapCase_25(Scene* scene, Vec2 position);
	~MapCase_25();

	void tick();
	void ClearOnDidFinish();
};
