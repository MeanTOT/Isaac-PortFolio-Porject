#pragma once
#include "ItemBase.h"

class Key : public ItemBase
{
private:

public:
	Key(Scene* scene, Vec2 position);
	~Key() {}

	void tick();
	void SetZorder();
	void EraseItem();
};