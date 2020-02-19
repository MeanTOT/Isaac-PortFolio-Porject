#pragma once
#include "ProjectFW.h"

class MonsterBase
{
protected:
	SpriteFrameCache* cache;

	Animation* monsterAnimation;
	Animate* monsterAnimate;

	Animation* monsterAnimation2;
	Animate* monsterAnimate2;

	float monsterHeight;
	float monsterMoveSpeed;
	float maxHp;
	float hp;

private:

public:
	MonsterBase();
	~MonsterBase();

	Sprite* monsterSprite;

	Sprite* monsterShadowSprite;

	PhysicsBody* monsterPhysics;

	virtual void tick() {}
	virtual void SetZorder() {}
	virtual void FollowPlayer() {}
	virtual void MonsterSetTag() {}
	virtual void MonsterEraseCall() {}
};