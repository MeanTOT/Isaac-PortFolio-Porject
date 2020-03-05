#pragma once
#include "MonsterBase.h"
#include "Bone.h"

class Boney : public MonsterBase
{
private:

public:
	Boney(Scene* scene, Vec2 position);
	~Boney() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void ChangeTag();

};