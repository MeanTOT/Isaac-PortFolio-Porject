#include "IsaacBoom.h"

IsaacBoom::IsaacBoom(Scene* scene, Vec2 position)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ITEMS/BOMBS.plist");
	cache->addSpriteFramesWithFile("ITEMS/ExplosionEffect.plist");

	Boom = Sprite::createWithSpriteFrameName("Bombs_05.png");
	Boom->setPosition(position.x + Player->getIsaacPysicBody()->getPositionOffset().x, position.y - 20 + Player->getIsaacPysicBody()->getPositionOffset().y);
	Boom->setAnchorPoint({ 0.5,0 });

	BoomPhysic = PhysicsBody::createCircle(Boom->getContentSize().width / 4, PhysicsMaterial(0.1f, 0, 0));
	BoomPhysic->setLinearDamping(1.0f);
	BoomPhysic->setContactTestBitmask(true);
	BoomPhysic->setCollisionBitmask(6);
	Boom->addComponent(BoomPhysic);

	scene->addChild(Boom, Player->getIsaacBody()->getZOrder() - 50000);

	BoomAnimation = Animation::create();
	BoomAnimation->setDelayPerUnit(0.05f);
	BoomAnimation->addSpriteFrame(cache->getSpriteFrameByName("Bombs_05.png"));
	BoomAnimation->addSpriteFrame(cache->getSpriteFrameByName("Bombs_11.png"));
	BoomAnimation->addSpriteFrame(cache->getSpriteFrameByName("Bombs_21.png"));
	BoomAnimation->addSpriteFrame(cache->getSpriteFrameByName("Bombs_22.png"));
	BoomAnimation->addSpriteFrame(cache->getSpriteFrameByName("Bombs_23.png"));
	BoomAnimate = Animate::create(BoomAnimation);
	BoomRepeat = Repeat::create(BoomAnimate, 10);
	BoomRepeat->retain();

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

	Boom->runAction(Sequence::create(BoomRepeat, CallFunc::create(CC_CALLBACK_0(IsaacBoom::ErasePhysicsBody, this)), ExplosionAnimate, RemoveSelf::create(), nullptr));

}

void IsaacBoom::ErasePhysicsBody()
{
	BoomPhysic->removeFromWorld();
	Player->setBombActivation(false);

	ExplosionPhysic = PhysicsBody::createBox(Boom->getContentSize() * 2, PhysicsMaterial(10, 0, 0));
	ExplosionPhysic->setContactTestBitmask(true);
	ExplosionPhysic->setCollisionBitmask(7);
	ExplosionPhysic->setPositionOffset(Vec2(35, 0));
	Boom->setPhysicsBody(ExplosionPhysic);

	SMI->PlayExplosion1();
}
