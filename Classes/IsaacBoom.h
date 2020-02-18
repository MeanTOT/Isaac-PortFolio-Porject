#pragma once
#include "ProjectFW.h"

class IsaacBoom
{
private:
	SpriteFrameCache* cache; // ĳ��

	Sprite* Boom;
	PhysicsBody* BoomPhysic; // Boom �������ٵ� 
	PhysicsBody* ExplosionPhysic; // ����ȿ�� �������ٵ� 

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