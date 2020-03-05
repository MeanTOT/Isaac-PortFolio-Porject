#pragma once
#include "MapBase.h"
#include "Bomb.h"

class MapCase_20 : public MapBase
{
private:
	EffectPoof* TumorMaker[2];
	Bomb* BombMaker;
public:
	MapCase_20(Scene* scene, Vec2 position);
	~MapCase_20();

	void tick();
	void ClearOnDidFinish();
};
