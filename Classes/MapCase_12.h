#pragma once
#include "MapBase.h"
#include "Coin.h"

class MapCase_12 : public MapBase
{
private:
	Rocks* RocksMaker[4];
	EffectPoof* TumorMaker;
	Coin* coinMaker;

public:
	MapCase_12(Scene* scene, Vec2 position);
	~MapCase_12();

	void tick();
	void ClearOnDidFinish();
};