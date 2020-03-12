#pragma once
#include "MapBase.h"

class MapCase_26 : public MapBase
{
private:
	Rocks* RocksMaker[16];
	Locks* LocksMaker;
	Pill* pillMaker;
public:
	MapCase_26(Scene* scene, Vec2 position);
	~MapCase_26();

	void tick();
	void ClearOnDidFinish();
};
