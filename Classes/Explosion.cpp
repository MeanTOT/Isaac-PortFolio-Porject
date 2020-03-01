#include "Explosion.h"

Explosion::Explosion(Scene * scene, Vec2 position, BombKind bombkind)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ITEMS/ExplosionEffect.plist");
	cache->addSpriteFramesWithFile("Bullet/Effect_BombRadius.plist");

	switch (bombkind)
	{
	case BaseMentBomb:
	{
		ExplosionSprite = Sprite::createWithSpriteFrameName("effect_explosion_01.png");
		ExplosionSprite->setPosition(position.x, position.y - 20);
		ExplosionSprite->setAnchorPoint({ 0.5,0 });

		ExplosionPhysic = PhysicsBody::createBox(ExplosionSprite->getContentSize(), PhysicsMaterial(10, 0, 0));
		ExplosionPhysic->setContactTestBitmask(true);
		ExplosionPhysic->setDynamic(false);
		ExplosionPhysic->setCollisionBitmask(7);
		ExplosionPhysic->setPositionOffset(Vec2(0, -30));
		ExplosionSprite->setPhysicsBody(ExplosionPhysic);

		scene->addChild(ExplosionSprite, Player->getIsaacBody()->getLocalZOrder());

		ExplosionAnimation = Animation::create();
		ExplosionAnimation->setDelayPerUnit(0.05f);
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_01.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_02.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_03.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_04.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_05.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_06.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_07.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_08.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_09.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_10.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_11.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_12.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_13.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_14.png"));
		ExplosionAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_explosion_15.png"));
		ExplosionAnimate = Animate::create(ExplosionAnimation);
		ExplosionAnimate->retain();

		ExplosionSprite->runAction(Sequence::create(ExplosionAnimate, RemoveSelf::create(), nullptr));
		ExplosionSprite->runAction(Sequence::create(DelayTime::create(0.05f), CallFunc::create(CC_CALLBACK_0(Explosion::ErasePhysicsBody, this)), nullptr));
	}
		break;
	default:
		break;
	}

	auto randomindex = RGI->getRandomNumberWithRange(1, 8);

	switch (randomindex)
	{
	case 1:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_01.png");
		break;
	case 2:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_02.png");
		break;
	case 3:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_03.png");
		break;
	case 4:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_04.png");
		break;
	case 5:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_05.png");
		break;
	case 6:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_06.png");
		break;
	case 7:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_07.png");
		break;
	case 8:
		ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_08.png");
		break;
	default:
		break;
	}

	ExplosionTraceSprite = Sprite::createWithSpriteFrameName("effect_bombradius_01.png");
	ExplosionTraceSprite->setPosition(ExplosionSprite->getPosition().x, ExplosionSprite->getPosition().y - 20);
	ExplosionTraceSprite->setAnchorPoint({ 0.5,0 });
	scene->addChild(ExplosionTraceSprite, Player->getIsaacBody()->getLocalZOrder() - 5000);

	SMI->PlayExplosion1();
}

void Explosion::ErasePhysicsBody()
{
	ExplosionPhysic->removeFromWorld();
}
