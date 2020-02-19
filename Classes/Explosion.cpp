#include "Explosion.h"

Explosion::Explosion(Scene * scene, Vec2 position, BombKind bombkind)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ITEMS/ExplosionEffect.plist");

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

		scene->addChild(ExplosionSprite, Player->getIsaacBody()->getZOrder());

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

		ExplosionSprite->runAction(Sequence::create(ExplosionAnimate, CallFunc::create(CC_CALLBACK_0(Explosion::ErasePhysicsBody, this)), RemoveSelf::create(), nullptr));
	}
		break;
	default:
		break;
	}
}

void Explosion::ErasePhysicsBody()
{
	ExplosionPhysic->removeFromWorld();
}
