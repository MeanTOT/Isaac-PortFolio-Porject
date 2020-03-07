#pragma once
#include "ProjectFW.h"
#include "Dregs.h"
#include "Coin.h"
#include "Key.h"
#include "Bomb.h"
#include "Heart.h"

class ObjectBase
{
private:


public:
	ObjectBase() {}
	~ObjectBase() {}

	int ObjectHp;
	int _index;

	Scene* _scene;
	Vec2 _position;
	
	SpriteFrameCache* Obcache;

	Sprite* ObjectSprite;
	PhysicsBody* ObjectPhysics;

	Animation* ObjectAnimation;
	Animate* ObjectAnimate;

	Coin* coinMaker;
	Key* keyMaker;
	Bomb* bombMaker;
	Heart* heartMaker;

	virtual void tick() {}
	virtual void CreateObject(Scene* scene, Vec2 position, int index) {}

	void RandomItemDrop();
	void RandomItemDropSpecial();
};