#pragma once
#include "ItemBase.h"

class Heart : public ItemBase
{
private:

public:
	Heart(Scene* scene, Vec2 position);
	~Heart() {}

	void tick();
	void SetZorder();
	void EraseItem();
};