#include "EffectPoof.h"

EffectPoof::EffectPoof(Scene * scene, Vec2 position, MonsterKind monsterkind)
{
	switch (monsterkind)
	{
	case MonsterKind_Fly:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateFly, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Dip:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateDip, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Horf:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateHorf, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Pooter:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreatePooter, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Dingle:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateDingle, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Tumor:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateTumor, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_BoomFly:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateBoomFly, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_WallCreep:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateWallCreep, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Nest:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateNest, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Boney:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateBoney, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Charger:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateCharger, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_Blubber:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateBlubber, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	case MonsterKind_MegaMaw:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Monster/Poof/Effect_Poof_Normal.plist");

		EffectPoofSprite = Sprite::createWithSpriteFrameName("effect_poof_01.png");
		EffectPoofSprite->setPosition(position);
		EffectPoofSprite->setScale(1.5f);
		EffectPoofSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectPoofSprite);

		EffectPoofAnimation = Animation::create();
		EffectPoofAnimation->setDelayPerUnit(0.05f);
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_01.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_02.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_03.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_04.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_05.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_06.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_07.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_08.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_09.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_10.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_11.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_12.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_13.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_14.png"));
		EffectPoofAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_poof_15.png"));
		EffectPoofAnimate = Animate::create(EffectPoofAnimation);
		EffectPoofAnimate->retain();

		EffectPoofSprite->runAction(Sequence::create(Spawn::createWithTwoActions(EffectPoofAnimate, CallFunc::create(CC_CALLBACK_0(EffectPoof::CreateMegaMaw, this, scene, position))), RemoveSelf::create(), nullptr));
	}
		break;
	default:
		break;
	}
}

void EffectPoof::CreateFly(Scene * scene, Vec2 position)
{
	FlyMaker = new Fly(scene, position);
}

void EffectPoof::CreateDip(Scene * scene, Vec2 position)
{
	DipMaker = new Dip(scene, position);
}

void EffectPoof::CreateHorf(Scene * scene, Vec2 position)
{
	HorfMaker = new Horf(scene, position);
}

void EffectPoof::CreatePooter(Scene * scene, Vec2 position)
{
	PooterMaker = new Pooter(scene, position);
}

void EffectPoof::CreateDingle(Scene * scene, Vec2 position)
{
	DingleMaker = new Dingle(scene, position);
}

void EffectPoof::CreateTumor(Scene * scene, Vec2 position)
{
	TumorMaker = new Tumor(scene, position);
}

void EffectPoof::CreateBoomFly(Scene * scene, Vec2 position)
{
	BoomFlyMaker = new BoomFly(scene, position);
}

void EffectPoof::CreateWallCreep(Scene * scene, Vec2 position)
{
	WallCreepMaker = new WallCreep(scene, position);
}

void EffectPoof::CreateNest(Scene * scene, Vec2 position)
{
	NestMaker = new Nest(scene, position);
}

void EffectPoof::CreateBoney(Scene * scene, Vec2 position)
{
	BoneyMaker = new Boney(scene, position);
}

void EffectPoof::CreateCharger(Scene * scene, Vec2 position)
{
	ChargerMaker = new Charger(scene, position);
}

void EffectPoof::CreateBlubber(Scene * scene, Vec2 position)
{
	BlubberMaker = new Blubber(scene, position);
}

void EffectPoof::CreateMegaMaw(Scene * scene, Vec2 position)
{
	MegaMawMaker = new MegaMaw(scene, position);
}




