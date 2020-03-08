#pragma once
#include "ItemBase.h"

class Pill : public ItemBase
{
private:

public:
	Pill(Scene* scene, Vec2 position);
	~Pill() {}

	void tick();
	void SetZorder();
	void EraseItem();
};