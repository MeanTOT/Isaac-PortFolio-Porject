#pragma once
#include "ProjectFW.h"

class ItemBase
{
protected:
	Sprite* itemSprite;

	Animation* itemAnimation;
	Animate* itemAnimate;
private:
	
public:
	ItemBase() {}
	~ItemBase() {}
};
