#pragma once
#include "MonsterBase.h"

enum ChargerDirection
{
	CHARGER_RIGHT = 1,
	CHARGER_LEFT,
	CHARGER_UP,
	CHARGER_DOWN,
};

class Charger : public MonsterBase
{
private:
	ChargerDirection chargerDirection;
public:
	Charger(Scene* scene, Vec2 position);
	~Charger() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void ChangeTag();
	void MakeAttackCycleZero();

};