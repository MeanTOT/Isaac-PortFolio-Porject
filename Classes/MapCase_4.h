#pragma once
#include "MapBase.h"

class MapCase_4 : public MapBase
{
private:
	Poop* PoopMaker[4];
	EffectPoof* DipMaker[4];
public:
	MapCase_4(Scene* scene, Vec2 position);
	~MapCase_4();

	void tick();
};
