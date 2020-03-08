#pragma once
#include "ItemBase.h"

class ShopItem_BloodOfTheMarTyr : public ItemBase
{
private:

public:
	ShopItem_BloodOfTheMarTyr(Scene* scene, Vec2 position);
	~ShopItem_BloodOfTheMarTyr() {}

	void tick();
	void SetZorder();
	void EraseItem();
};