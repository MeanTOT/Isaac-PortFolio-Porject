#pragma once
#include "ObjectBase.h"

class ShopPriceNumber : public ObjectBase
{
private:

public:
	ShopPriceNumber() {}
	~ShopPriceNumber() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);
};
