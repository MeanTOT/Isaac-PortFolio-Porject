#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"

class Pooter : public MonsterBase
{
private:

public:
	Pooter(Scene* scene, Vec2 position);
	~Pooter() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void ChangeTag();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();

};