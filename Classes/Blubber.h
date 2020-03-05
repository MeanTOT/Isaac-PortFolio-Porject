#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"

class Blubber : public MonsterBase
{
private:

public:
	Blubber(Scene* scene, Vec2 position);
	~Blubber() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void ChangeTag();

};