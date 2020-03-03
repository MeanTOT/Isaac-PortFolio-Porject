#pragma once
#include "ItemBase.h"

class MagicMushRoom : public ItemBase
{
private:
	EaseInOut* act1;
public:
	MagicMushRoom(Scene* scene, Vec2 position);
	~MagicMushRoom() {}

	void tick();
	void SetZorder();
	void EraseItem();
};