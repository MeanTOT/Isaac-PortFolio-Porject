#pragma once
#include "MapBase.h"

class MapCase_2 : public MapBase
{
private:
	Rocks* RocksMaker;
public:
	MapCase_2(Scene* scene, Vec2 position);
	~MapCase_2();

	void tick();
};