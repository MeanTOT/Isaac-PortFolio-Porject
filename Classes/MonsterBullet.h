#pragma once
#include "ProjectFW.h"

class MonsterBullet
{
private:

	SpriteFrameCache* cache;

	Animation* BulletEraseAnimation;
	Animate* BulletEraseAnimate;

	Sequence* eraseAction1;
	Sequence* eraseAction2;
	Sequence* eraseAction3;

	float range;
	float _impulseX;
	float _impulseY;
	float _height;

public:
	MonsterBullet();
	~MonsterBullet() {};

	Sprite* bullet;
	PhysicsBody* bulletPhysics;
	Sprite* bulletShadow;
	PhysicsBody* bulletShadowPhysics;

	void CreateIsaacBullet(Scene* scene, Vec2 position, float ImpulseX, float ImpulseY, float height);
	void tick();
	void MoveBullet();
	void EraseBullet();
	void RangeCount();
	void ErasePhysicsBody();
	void EraseBulletVec();
	void PlayBulletEraseSound();
	void SetZorder();
	void ChangeTag();

};