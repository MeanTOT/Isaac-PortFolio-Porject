#pragma once
#include "ObjectBase.h"

class ShopMaster : public ObjectBase
{
private:

public:
	ShopMaster() {}
	~ShopMaster() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);
};
