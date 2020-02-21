#pragma once
#include "MapBase.h"

class MapCase_6 : public MapBase
{
private:
	Rocks* RocksMaker[20];
public:
	MapCase_6(Scene* scene, Vec2 position);
	~MapCase_6();

	void tick();
};
