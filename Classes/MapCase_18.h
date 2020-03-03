#pragma once
#include "MapBase.h"
#include "Coin.h"

class MapCase_18 : public MapBase
{
private:
	EffectPoof* FlyMaker[8];
	MushRoom* MushRoomMaker[12];
	Coin* CoinMaker;
public:
	MapCase_18(Scene* scene, Vec2 position);
	~MapCase_18();

	void tick();
	void ClearOnDidFinish();
};
