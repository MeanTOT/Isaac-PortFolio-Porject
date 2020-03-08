#pragma once
#include "MapBase.h"
#include "Heart.h"
#include "Pill.h"

class MapCase_2 : public MapBase
{
private:
	Rocks* RocksMaker[4];
	Poop* PoopMaker[2];
	Pill* pill;
public:
	MapCase_2(Scene* scene, Vec2 position);
	~MapCase_2();

	void tick();
};