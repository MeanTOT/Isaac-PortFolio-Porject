#pragma once
#include "MapBase.h"

class MapCase_1 : public MapBase
{
private:
	Sprite* controlsImage;
public:
	MapCase_1(Scene* scene, Vec2 position);
	~MapCase_1();

	void tick();
};