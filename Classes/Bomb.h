#pragma once
#include "ItemBase.h"

class Bomb : public ItemBase
{
private:

public:
	Bomb(Scene* scene, Vec2 position);
	~Bomb() {}

	void tick();
	void SetZorder();
	void EraseItem();
};