#include "Bullet.h"

Bullet::Bullet()
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Bullet/Effect_Tearpoofa.plist");
}

void Bullet::CreateIsaacBullet(Scene* scene, Vec2 position)
{
	BulletEraseAnimation = Animation::create();
	BulletEraseAnimation->setDelayPerUnit(0.04f);
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_01.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_02.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_03.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_04.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_05.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_06.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_07.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_08.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_09.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_10.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_11.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_12.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_13.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_14.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_15.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_tearpoofa_16.png"));
	BulletEraseAnimate = Animate::create(BulletEraseAnimation);
	BulletEraseAnimate->retain();

	eraseAction1 = Sequence::create(MoveBy::create(0.2f, Vec2(0, -Player->getMaxHeight())), CallFunc::create(CC_CALLBACK_0(Bullet::ErasePhysicsBody, this)),BulletEraseAnimate,
		CallFunc::create(CC_CALLBACK_0(Bullet::EraseBulletVec, this)), RemoveSelf::create(), nullptr);
	eraseAction1->setTag(1);
	eraseAction1->retain();
	eraseAction2 = Sequence::create(BulletEraseAnimate, CallFunc::create(CC_CALLBACK_0(Bullet::EraseBulletVec, this)),RemoveSelf::create(),nullptr);
	eraseAction2->setTag(2);
	eraseAction2->retain();

	bullet = Sprite::create("Bullet/tears_06.png");
	bullet->setPosition(position.x + Player->getIsaacPysicBody()->getPositionOffset().x, position.y + 10 + Player->getIsaacPysicBody()->getPositionOffset().y);
	bullet->setTag(ActivationBulletTag);

	bulletPhysics = PhysicsBody::createCircle(bullet->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
	//bulletPhysics->setPositionOffset(Vec2(0, -Player->getBasicHeight()));
	bulletPhysics->setContactTestBitmask(true);
	bulletPhysics->setCollisionBitmask(0);
	bullet->addComponent(bulletPhysics);

	scene->addChild(bullet);

	bulletShadow = Sprite::create("Player/shadow.png");
	bulletShadow->setPosition(bullet->getPosition().x, bullet->getPosition().y - Player->getBasicHeight());
	bulletShadow->setScale(0.1f);
	bulletShadow->setOpacity(100);
	bulletShadow->setTag(ActivationBulletTag);

	bulletShadowPhysics = PhysicsBody::createCircle(bulletShadow->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
	bulletShadowPhysics->setPositionOffset(Vec2(0, 0));
	bulletShadowPhysics->setContactTestBitmask(true);
	bulletShadowPhysics->setCollisionBitmask(5);
	bulletShadow->addComponent(bulletShadowPhysics);

	scene->addChild(bulletShadow , -2);

	range = Player->getBulletRange() / Player->getMaxHeight();
	
	MoveBullet();
}

void Bullet::tick()
{
	RangeCount();
	EraseBullet();
}

void Bullet::MoveBullet()
{
	if (Player->getBulletFireR())
	{
		bulletPhysics->applyImpulse(Vec2(Player->getBulletMoveSpeed() / Player->getMaxHeight(), Player->getIsaacPysicBody()->getVelocity().y / 4));
		bulletShadowPhysics->applyImpulse(Vec2(Player->getBulletMoveSpeed() / Player->getMaxHeight(), Player->getIsaacPysicBody()->getVelocity().y / 4));
	}
	else if (Player->getBulletFireL())
	{
		bulletPhysics->applyImpulse(Vec2(-1 * (Player->getBulletMoveSpeed() / Player->getMaxHeight()), Player->getIsaacPysicBody()->getVelocity().y / 4));
		bulletShadowPhysics->applyImpulse(Vec2(-1 * (Player->getBulletMoveSpeed() / Player->getMaxHeight()), Player->getIsaacPysicBody()->getVelocity().y / 4));
	}
	else if (Player->getBulletFireU())
	{
		bulletPhysics->applyImpulse(Vec2(Player->getIsaacPysicBody()->getVelocity().x / 4, Player->getBulletMoveSpeed() / Player->getMaxHeight()));
		bulletShadowPhysics->applyImpulse(Vec2(Player->getIsaacPysicBody()->getVelocity().x / 4, Player->getBulletMoveSpeed() / Player->getMaxHeight()));
	}
	else if (Player->getBulletFireD())
	{
		bulletPhysics->applyImpulse(Vec2(Player->getIsaacPysicBody()->getVelocity().x / 4, -1 * (Player->getBulletMoveSpeed() / Player->getMaxHeight())));
		bulletShadowPhysics->applyImpulse(Vec2(Player->getIsaacPysicBody()->getVelocity().x / 4, -1 * (Player->getBulletMoveSpeed() / Player->getMaxHeight())));
	}
}

void Bullet::EraseBullet()
{
	if (bulletShadow->getTag() == EraseBulletTag)
	{
		if (!bullet->getNumberOfRunningActionsByTag(2))
		{
			bullet->stopAllActions();

			bullet->runAction(eraseAction2);
			bulletShadow->runAction(Sequence::create(DelayTime::create(5), RemoveSelf::create(), nullptr));

			ErasePhysicsBody();
		}
	}

	if (bulletShadow->getTag() == EraseBulletTag2)
	{
		if (!bullet->getNumberOfRunningActionsByTag(1))
		{
			bullet->runAction(eraseAction1);
			bulletShadow->runAction(Sequence::create(DelayTime::create(5), RemoveSelf::create(), nullptr));
		}
	}
}

void Bullet::RangeCount()
{
	if (bulletShadow->getTag() == ActivationBulletTag)
		range -= 0.6f;
	
	if (range <= 0)
	{
		bulletShadow->setTag(EraseBulletTag2);
		range = 1;
	}

}

void Bullet::ErasePhysicsBody()
{
	bulletPhysics->removeFromWorld();
	bulletShadowPhysics->removeFromWorld();
	bulletShadow->setVisible(false);
}

void Bullet::EraseBulletVec()
{
	bulletShadow->setTag(EraseOnVec);
}


