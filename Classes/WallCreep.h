#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"

class WallCreep : public MonsterBase
{
private:

public:
	WallCreep(Scene* scene, Vec2 position);
	~WallCreep() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void ChangeTag();

};