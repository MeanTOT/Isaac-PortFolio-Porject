#pragma once
#include "MapBase.h"

class MapCase_ItemRoom1 : public MapBase
{
private:
	Sprite* altar;
public:
	MapCase_ItemRoom1(Scene* scene, Vec2 position);
	~MapCase_ItemRoom1();

	void tick();
};
