#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"
#include "Heart.h"

class EffectPoof;

class Dingle : public MonsterBase
{
private:
	ProgressTimer* bossHpBar;
	Sprite* bossHpBackBar;
	Heart* heartMaker[2];
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
	void DingleRushSound();
	void DIngleBulletFireSound();
	void ResetAttackCycle();
	void CreateDropItem();

};