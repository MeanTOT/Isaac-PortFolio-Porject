#pragma once
#include "ProjectFW.h"
#include "EffectBlood.h"
#include "Dregs.h"

class MonsterBase
{
protected:
	Scene* _scene;
	Vec2 _position;

	SpriteFrameCache* cache;

	Animation* monsterAnimation;
	Animate* monsterAnimate;
	RepeatForever* monsterRepeatForever;

	Animation* monsterAnimation2;
	Animate* monsterAnimate2;
	RepeatForever* monsterRepeatForever2;

	Animation* monsterAnimation3;
	Animate* monsterAnimate3;
	RepeatForever* monsterRepeatForever3;

	Animation* monsterAnimation4;
	Animate* monsterAnimate4;
	RepeatForever* monsterRepeatForever4;

	Animation* monsterAnimation5;
	Animate* monsterAnimate5;
	RepeatForever* monsterRepeatForever5;

	Animation* monsterAnimation6;
	Animate* monsterAnimate6;
	RepeatForever* monsterRepeatForever6;

	Animation* monsterAnimation7;
	Animate* monsterAnimate7;
	RepeatForever* monsterRepeatForever7;

	float monsterHeight;
	float monsterMoveSpeed;
	float mosnterBulletMoveSpeed;
	float monsterAngle;
	float maxHp;
	float hp;
	

	float AttackCycle;
	float AttackCycle2;

private:

public:
	MonsterBase();
	~MonsterBase();

	Sprite* monsterSprite;
	Sprite* monsterSubSprite;
	Sprite* monsterShadowSprite;

	PhysicsBody* monsterPhysics;

	EffectBlood* effectBlood;
	Dregs* _dregs;

	virtual void tick() {}
	virtual void SetZorder() {}
	virtual void FollowPlayer() {}
	virtual void MonsterSetTag() {}
	virtual void MonsterEraseCall() {}
	virtual void ChangeTag() {}
	virtual void DoAttack() {}
	virtual void CreateBullet() {}

	void HitEffect();
	void HitEffect2();
	void ChangeColor();
	void ChangeColor2();
	float GetAngleToPlayer();
};