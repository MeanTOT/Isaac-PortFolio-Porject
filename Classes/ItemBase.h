#pragma once
#include "ProjectFW.h"

class ItemBase
{
protected:
	SpriteFrameCache* cache;

	Animation* itemAnimation1;
	Animate* itemAnimate1;
	RepeatForever* itemRepeatForever1;
	Animation* itemAnimation2;
	Animate* itemAnimate2;
	RepeatForever* itemRepeatForever2;
	Animation* itemAnimation3;
	Animate* itemAnimate3;
	RepeatForever* itemRepeatForever3;
private:
	
public:
	ItemBase() {}
	~ItemBase() {}

	Sprite* itemSprite;
	PhysicsBody* itemPhysics;

	virtual void tick() {}
	virtual void SetZorder() {}
	virtual void EraseItem() {}

	void ItemSummonAnimation(Sprite* pSprite);
};
