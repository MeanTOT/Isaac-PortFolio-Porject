#pragma once
#include "ProjectFW.h"
#include "Fly.h"
#include "Dip.h"
#include "Horf.h"
#include "Pooter.h"
#include "Dingle.h"
#include "Tumor.h"
#include "BoomFly.h"
#include "WallCreep.h"
#include "Nest.h"

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
	Pooter* PooterMaker;
	Dingle* DingleMaker;
	Tumor* TumorMaker;
	BoomFly* BoomFlyMaker;
	WallCreep* WallCreepMaker;
	Nest* NestMaker;

public:
	EffectPoof(Scene* scene, Vec2 position, MonsterKind monsterkind);
	~EffectPoof() {}

	void CreateFly(Scene * scene, Vec2 position);
	void CreateDip(Scene * scene, Vec2 position);
	void CreateHorf(Scene * scene, Vec2 position);
	void CreatePooter(Scene* scene, Vec2 position);
	void CreateDingle(Scene* scene, Vec2 position);
	void CreateTumor(Scene* scene, Vec2 position);
	void CreateBoomFly(Scene* scene, Vec2 position);
	void CreateWallCreep(Scene* scene, Vec2 position);
	void CreateNest(Scene* scene, Vec2 position);


};



