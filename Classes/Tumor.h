#pragma once
#include "MonsterBase.h"
#include "MonsterBullet.h"

class Tumor : public MonsterBase
{
private:

public:
	Tumor(Scene* scene, Vec2 position);
	~Tumor() {}

	void tick();
	void SetZorder();
	void ChangeTag();
	void MonsterSetTag();
	void DoAttack();
	void CreateBullet();
	void FollowPlayer();

};