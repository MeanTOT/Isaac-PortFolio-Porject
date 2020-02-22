#include "EffectBlood.h"

EffectBlood::EffectBlood(Scene * scene, Vec2 position, MonsterKind monsterkind)
{
	switch (monsterkind)
	{
	case MonsterKind_Fly:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Object/Dregs/Effect_BloodStains.plist");

		auto randomindex = RGI->getRandomNumberWithRange(1, 6);

		switch (randomindex)
		{
		case 1:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_02.png");
		}
		break;
		case 2:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_03.png");
		}
		break;
		case 3:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_05.png");
		}
		break;
		case 4:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_06.png");
		}
		break;
		case 5:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_09.png");
		}
		break;
		case 6:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_10.png");
		}
		break;
		default:
			break;
		}

		EffectBloodSprite->setPosition(position);
		EffectBloodSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectBloodSprite, -20000);
	}
	break;
	case MonsterKind_Dip:
	{
	
	}
	case MonsterKind_Horf:
	{
		cache = SpriteFrameCache::getInstance();
		cache->addSpriteFramesWithFile("Object/Dregs/Effect_BloodStains.plist");

		auto randomindex = RGI->getRandomNumberWithRange(1, 6);

		switch (randomindex)
		{
		case 1:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_01.png");
		}
		break;
		case 2:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_08.png");
		}
		break;
		case 3:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_15.png");
		}
		break;
		case 4:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_20.png");
		}
		break;
		case 5:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_24.png");
		}
		break;
		case 6:
		{
			EffectBloodSprite = Sprite::createWithSpriteFrameName("effect_bloodstains_28.png");
		}
		break;
		default:
			break;
		}

		EffectBloodSprite->setPosition(position.x, position.y - 20);
		EffectBloodSprite->setAnchorPoint({ 0.5,0 });
		scene->addChild(EffectBloodSprite, -20000);
	}
		break;
	default:
		break;
	}
}
