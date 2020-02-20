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

	scene->addChild(Boom, Player->getIsaacBody()->getLocalZOrder());

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

	Boom->runAction(Sequence::create(BoomRepeat, CallFunc::create(CC_CALLBACK_0(IsaacBoom::ErasePhysicsBody, this)),
		CallFunc::create(CC_CALLBACK_0(IsaacBoom::CreateExplosion, this, scene, position)), RemoveSelf::create(), nullptr));

}

void IsaacBoom::ErasePhysicsBody()
{
	BoomPhysic->removeFromWorld();
	Player->setBombActivation(false);

	ExplosionPhysic = PhysicsBody::createBox(Boom->getContentSize() * 2, PhysicsMaterial(10, 0, 0));
	ExplosionPhysic->setContactTestBitmask(true);
	ExplosionPhysic->setDynamic(false);
	ExplosionPhysic->setCollisionBitmask(7);
	ExplosionPhysic->setPositionOffset(Vec2(35, 0));
	Boom->setPhysicsBody(ExplosionPhysic);

	SMI->PlayExplosion1();
}

void IsaacBoom::CreateExplosion(Scene* scene, Vec2 position)
{
	explosion = new Explosion(scene, position, BaseMentBomb);
}
