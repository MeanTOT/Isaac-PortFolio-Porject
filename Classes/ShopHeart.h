#pragma once
#include "ItemBase.h"

class ShopHeart : public ItemBase
{
private:

public:
	ShopHeart(Scene* scene, Vec2 position);
	~ShopHeart() {}

	void tick();
	void SetZorder();
	void EraseItem();
};