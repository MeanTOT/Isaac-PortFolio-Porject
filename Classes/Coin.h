#pragma once
#include "ItemBase.h"

class Coin : public ItemBase
{
private:

public:
	Coin(Scene* scene, Vec2 position);
	~Coin() {}
};