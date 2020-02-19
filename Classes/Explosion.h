#pragma once
#include "ProjectFW.h"

class Explosion
{
private:
	SpriteFrameCache* cache; // Ä³½¬

	Sprite* ExplosionSprite;
	PhysicsBody* ExplosionPhysic;

	Animation* ExplosionAnimation;
	Animate* ExplosionAnimate;

public:
	Explosion(Scene* scene, Vec2 position, BombKind bombkind);
	~Explosion() {}

	void ErasePhysicsBody();
};