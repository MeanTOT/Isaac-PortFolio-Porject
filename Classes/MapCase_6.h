#pragma once
#include "MapBase.h"

class MapCase_6 : public MapBase
{
private:
	Rocks* RocksMaker[15];
	Fire* FireMaker[8];
public:
	MapCase_6(Scene* scene, Vec2 position);
	~MapCase_6();

	void tick();
};
