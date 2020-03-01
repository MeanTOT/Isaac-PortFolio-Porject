#pragma once
#include "MapBase.h"
#include "Coin.h"

class MapCase_13 : public MapBase
{
private:
	Rocks* RocksMaker[10];
	EffectPoof* BoomFlyMaker[4];
public:
	MapCase_13(Scene* scene, Vec2 position);
	~MapCase_13();

	void tick();
	void ClearOnDidFinish();
};