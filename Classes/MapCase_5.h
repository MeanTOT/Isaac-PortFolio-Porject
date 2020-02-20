#pragma once
#include "MapBase.h"

class MapCase_5 : public MapBase
{
private:
	Rocks* RocksMaker[17];
public:
	MapCase_5(Scene* scene, Vec2 position);
	~MapCase_5();

	void tick();
};
