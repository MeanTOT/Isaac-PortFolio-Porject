#pragma once
#include "ProjectFW.h"
#include "Dregs.h"

class ObjectBase
{
private:


public:
	ObjectBase() {}
	~ObjectBase() {}

	int ObjectHp;
	int _index;

	Scene* _scene;
	
	SpriteFrameCache* Obcache;

	Sprite* ObjectSprite;
	PhysicsBody* ObjectPhysics;

	Animation* ObjectAnimation;
	Animate* ObjectAnimate;

	virtual void tick() {}
	virtual void CreateObject(Scene* scene, Vec2 position, int index) {}
};