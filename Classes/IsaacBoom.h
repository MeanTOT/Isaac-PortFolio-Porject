#pragma once
#include "ProjectFW.h"
#include "Explosion.h"

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

	Explosion* explosion;

public:
	IsaacBoom(Scene* scene, Vec2 position);
	~IsaacBoom() {}

	void ErasePhysicsBody();
	void CreateExplosion(Scene* scene, Vec2 position);
};
