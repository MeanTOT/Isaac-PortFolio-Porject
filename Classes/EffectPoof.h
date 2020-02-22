#pragma once
#include "ProjectFW.h"
#include "Fly.h"
#include "Dip.h"
#include "Horf.h"

class EffectPoof
{
private:
	SpriteFrameCache* cache;

	Sprite* EffectPoofSprite;

	Animation* EffectPoofAnimation;
	Animate* EffectPoofAnimate;

	Fly* FlyMaker;
	Dip* DipMaker;
	Horf* HorfMaker;

public:
	EffectPoof(Scene* scene, Vec2 position, MonsterKind monsterkind);
	~EffectPoof() {}

	void CreateFly(Scene * scene, Vec2 position);
	void CreateDip(Scene * scene, Vec2 position);
	void CreateHorf(Scene * scene, Vec2 position);
};



