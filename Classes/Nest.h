#pragma once
#include "MonsterBase.h"

class Nest : public MonsterBase
{
private:

public:
	Nest(Scene* scene, Vec2 position);
	~Nest() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
	void CreateBullet();
	void ChangeTag();

};