#pragma once
#include "MapBase.h"

class MapCase_3 : public MapBase
{
private:
	Poop* PoopMaker[6];
public:
	MapCase_3(Scene* scene, Vec2 position);
	~MapCase_3();

	void tick();
};
