#pragma once
#include "MapBase.h"

class MapCase_24_ShopRoom : public MapBase
{
private:
	ShopMaster* shopMasgerMaker;
	Fire* fireMaker[2];
	ShopPriceNumber* ShopPriceNumberMaker[10];
	ShopHeart* shopHeartMaker;
	ShopKey* shopKeyMaker;
	ShopItem_BloodOfTheMarTyr* shopItem_BloodOfTheMarTyrMaker;
public:
	MapCase_24_ShopRoom(Scene* scene, Vec2 position);
	~MapCase_24_ShopRoom();

	void tick();
};