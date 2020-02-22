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



