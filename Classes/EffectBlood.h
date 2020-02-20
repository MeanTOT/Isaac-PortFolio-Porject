#pragma once
#include "ProjectFW.h"

class EffectBlood
{
private:
	SpriteFrameCache* cache;

	Sprite* EffectBloodSprite;

	Animation* EffectBloodAnimation;
	Animate* EffectBloodAnimate;

public:
	EffectBlood(Scene* scene, Vec2 position, MonsterKind monsterkind);
	~EffectBlood() {}

	void CreateFly(Scene * scene, Vec2 position);
	void CreateDip(Scene * scene, Vec2 position);
};



