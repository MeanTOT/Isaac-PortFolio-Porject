#pragma once
#include "MonsterBase.h"
#include "Fly.h"

class Nest : public MonsterBase
{
private:
	Fly* FlyMaker[2];
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