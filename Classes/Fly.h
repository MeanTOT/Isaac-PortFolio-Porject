#pragma once
#include "MonsterBase.h"

class Fly : public MonsterBase
{
private:

public:
	Fly(Scene* scene, Vec2 position);
	~Fly() {}

	void tick();
	void SetZorder();
	void FollowPlayer();
	void MonsterSetTag();
	void MonsterEraseCall();

};