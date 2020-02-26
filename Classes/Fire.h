#pragma once
#include "ObjectBase.h"

class Fire : public ObjectBase
{
private:

public:
	Fire() {}
	~Fire() {}

	Sprite* fire;
	Sprite* poof;

	Animation* poofAnimation;
	Animate* poofAnimate;

	void CreateObject(Scene* scene, Vec2 position, int index);
	void tick();
};


