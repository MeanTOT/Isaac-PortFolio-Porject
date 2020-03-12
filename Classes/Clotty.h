#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"

class Clotty : public MonsterBase
{
private:

public:
	Clotty(Scene* scene, Vec2 position);
	~Clotty() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void ChangeTag();

};