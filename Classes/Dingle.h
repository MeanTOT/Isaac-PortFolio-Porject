#pragma once
#include "MonsterBase.h"

class Dingle : public MonsterBase
{
private:

public:
	Dingle(Scene* scene, Vec2 position);
	~Dingle() {}

	void tick();
	void SetZorder();
	void ChangeTag();
	void MonsterSetTag();
	void MonsterEraseCall();
	void DoAttack();
};