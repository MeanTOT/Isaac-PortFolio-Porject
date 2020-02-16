#include "Bullet.h"

Bullet::Bullet()
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Bullet/Effect_Tearpoofa.plist");
}

void Bullet::CreateIsaacBullet(Scene* scene, Vec2 position)
{
	BulletEraseAnimation = Animation::create();
	BulletEraseAnimation->setDelayPerUnit(0.07f);
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

	bullet = Sprite::create("Bullet/tears_08.png");
	bullet->setPosition(position.x + Player->getIsaacPysicBody()->getPositionOffset().x, position.y + 10 + Player->getIsaacPysicBody()->getPositionOffset().y);
	bullet->setTag(ActivationBulletTag);

	bulletPhysics = PhysicsBody::createCircle(bullet->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
	bulletPhysics->setPositionOffset(Vec2(0, -Player->getBasicHeight()));
	bulletPhysics->setContactTestBitmask(true);
	bulletPhysics->setCollisionBitmask(5);
	bullet->addComponent(bulletPhysics);

	scene->addChild(bullet);

	bulletShadow = Sprite::create("Player/shadow.png");
	bulletShadow->setPosition(bullet->getPosition().x, bullet->getPosition().y - Player->getBasicHeight());
	bulletShadow->setScale(0.1f);
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
	if (bullet->getTag() == EraseBulletTag)
	{
		if (!bullet->getNumberOfRunningActions())
		{
			if (range <= 0)
			{
				bullet->runAction(Sequence::create(MoveBy::create(0.2f,Vec2(0, -Player->getMaxHeight())), CallFunc::create(CC_CALLBACK_0(Bullet::ErasePhysicsBody,this)),
					BulletEraseAnimate, RemoveSelf::create(), nullptr));

				log("액션실행");
			}
			else
			{
				bullet->runAction(Sequence::create(BulletEraseAnimate, RemoveSelf::create(), nullptr));

				bulletPhysics->removeFromWorld();
				bulletShadowPhysics->removeFromWorld();

				bulletShadow->removeFromParent();
			}
		}
	}
}

void Bullet::RangeCount()
{
	if (bullet->getTag() == ActivationBulletTag)
		range -= 0.6f;

	log("%f", range);
	
	if (range <= 0)
	{
		bullet->setTag(EraseBulletTag);
	}
}

void Bullet::ErasePhysicsBody()
{
	bulletPhysics->removeFromWorld();
	bulletShadowPhysics->removeFromWorld();

	bulletShadow->removeFromParent();
}

