#pragma once
#include "MapBase.h"

class MapCase_4 : public MapBase
{
private:
	Rocks* RocksMaker;
public:
	MapCase_4(Scene* scene, Vec2 position);
	~MapCase_4();

	void tick();
};
