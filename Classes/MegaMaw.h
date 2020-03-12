#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"

class MegaMaw : public MonsterBase
{
private:
	ProgressTimer* bossHpBar;
	Sprite* bossHpBackBar;

	
	Sequence* act1;
	Sequence* act2;
	Sequence* act3;
public:
	MegaMaw(Scene* scene, Vec2 position);
	~MegaMaw() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void CreateBullet2();
	void SetAttackCycle();
	void ChangeTag();
	void SetCollisionBitMaskZero();
	void SetCollisionBitMaskBasic();
	void SetPositionToPlayerPosition();
	void RunShadowMoveAction();
	void CreateDregs();
	void PlaySoundStomp();

};