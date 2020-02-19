#pragma once
#include "ProjectFW.h"
#include "Explosion.h"

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

	Explosion* explosion;

public:
	IsaacBoom(Scene* scene, Vec2 position);
	~IsaacBoom() {}

	void ErasePhysicsBody();
	void CreateExplosion(Scene* scene, Vec2 position);
};
