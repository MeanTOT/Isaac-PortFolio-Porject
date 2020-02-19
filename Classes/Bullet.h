#pragma once
#include "ProjectFW.h"

class Bullet
{
private:

	SpriteFrameCache* cache;

	Animation* BulletEraseAnimation;
	Animate* BulletEraseAnimate;

	Sequence* eraseAction1;
	Sequence* eraseAction2;

	float range;

public:
	Bullet();
	~Bullet() {};

	Sprite* bullet;
	PhysicsBody* bulletPhysics;
	Sprite* bulletShadow;
	PhysicsBody* bulletShadowPhysics;

	void CreateIsaacBullet(Scene* scene, Vec2 position);
	void tick();
	void MoveBullet();
	void EraseBullet();
	void RangeCount();
	void ErasePhysicsBody();
	void EraseBulletVec();
	void PlayBulletEraseSound();
	void SetZorder();
	
};