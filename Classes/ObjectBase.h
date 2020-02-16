#pragma once
#include "ProjectFW.h"

class ObjectBase
{
private:


public:
	ObjectBase() {}
	~ObjectBase() {}

	int ObjectHp;
	int _index;
	
	SpriteFrameCache* Obcache;

	Sprite* ObjectSprite;
	PhysicsBody* ObjectPhysics;

	Animation* ObjectAnimation;
	Animate* ObjectAnimate;

	virtual void tick() {}
	virtual void CreateObject(Scene* scene, Vec2 position, int index) {}
};