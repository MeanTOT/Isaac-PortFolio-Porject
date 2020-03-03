#pragma once
#include "MapBase.h"
#include "MagicMushRoom.h"

class MapCase_16_ItemRoom2 : public MapBase
{
private:
	Rocks* RockMaker[8];
	altar* _altar;
	MagicMushRoom* _magicMushRoom;
public:
	MapCase_16_ItemRoom2(Scene* scene, Vec2 position);
	~MapCase_16_ItemRoom2();

	void tick();
};
