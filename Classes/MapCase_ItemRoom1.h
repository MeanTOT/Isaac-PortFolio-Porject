#pragma once
#include "MapBase.h"
#include "Stigmata.h"

class MapCase_ItemRoom1 : public MapBase
{
private:
	Poop* PoopMaker[2];
	altar* _altar;
	Stigmata* _stigmata;
public:
	MapCase_ItemRoom1(Scene* scene, Vec2 position);
	~MapCase_ItemRoom1();

	void tick();
};
