#pragma once
#include "MonsterBase.h"

#include "MonsterBullet.h"

class EffectPoof;

enum DingleInfo
{
	DingleRight = 1,
	DingleLeft,
	DingleTop,
	DingleBottom,
};

class Dingle : public MonsterBase
{
private:
	DingleInfo dingleInfo;
	ProgressTimer* bossHpBar;
	Sprite* bossHpBackBar;
public:
	Dingle(Scene* scene, Vec2 position);
	~Dingle() {}

	void tick();
	void SetZorder();
	void ChangeTag();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void RushAttack();
	void SommonsDip();
	void CreateTrace();

};