#pragma once
#include "ItemBase.h"

class ShopKey : public ItemBase
{
private:

public:
	ShopKey(Scene* scene, Vec2 position);
	~ShopKey() {}

	void tick();
	void SetZorder();
	void EraseItem();
};