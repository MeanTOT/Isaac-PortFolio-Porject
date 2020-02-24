#pragma once
#include "ItemBase.h"

class Stigmata : public ItemBase
{
private:
	EaseInOut* act1;
public:
	Stigmata(Scene* scene, Vec2 position);
	~Stigmata() {}

	void tick();
	void SetZorder();
	void EraseItem();
};