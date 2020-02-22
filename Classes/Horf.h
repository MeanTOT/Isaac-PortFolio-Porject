#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"

class Horf : public MonsterBase
{
private:

public:
	Horf(Scene* scene, Vec2 position);
	~Horf() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();

};