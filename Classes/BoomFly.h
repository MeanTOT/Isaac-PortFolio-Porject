#pragma once
#include "MonsterBase.h"
#include "Explosion.h"

class BoomFly : public MonsterBase
{
private:
	Explosion* explosionMaker;
public:
	BoomFly(Scene* scene, Vec2 position);
	~BoomFly() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();

};