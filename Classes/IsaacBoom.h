#pragma once
#include "ProjectFW.h"

class IsaacBoom
{
private:
	SpriteFrameCache* cache; // 캐쉬

	Sprite* Boom;
	PhysicsBody* BoomPhysic; // Boom 피직스바디 
	PhysicsBody* ExplosionPhysic; // 폭발효과 피직스바디 

	Animation* BoomAnimation;
	Animate* BoomAnimate;
	Repeat* BoomRepeat;

	Animation* ExplosionAnimation;
	Animate* ExplosionAnimate;

public:
	IsaacBoom(Scene* scene, Vec2 position);
	~IsaacBoom() {}

	void ErasePhysicsBody();
};