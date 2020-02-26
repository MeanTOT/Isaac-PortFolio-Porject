#pragma once
#include "ItemBase.h"

class TheSadOnion : public ItemBase
{
private:
	EaseInOut* act1;
public:
	TheSadOnion(Scene* scene, Vec2 position);
	~TheSadOnion() {}

	void tick();
	void SetZorder();
	void EraseItem();
};