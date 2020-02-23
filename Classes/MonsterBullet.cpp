#include "MonsterBullet.h"

MonsterBullet::MonsterBullet()
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Bullet/EnemyBullets.plist");
	cache->addSpriteFramesWithFile("Bullet/Effect_BloodTear.plist");
}

void MonsterBullet::CreateIsaacBullet(Scene * scene, Vec2 position, float ImpulseX, float ImpulseY, float height)
{
	BulletEraseAnimation = Animation::create();
	BulletEraseAnimation->setDelayPerUnit(0.04f);
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_01.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_02.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_03.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_04.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_05.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_06.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_07.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_08.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_09.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_10.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_11.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_12.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_13.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_14.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_15.png"));
	BulletEraseAnimation->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodtear_16.png"));
	BulletEraseAnimate = Animate::create(BulletEraseAnimation);
	BulletEraseAnimate->retain();

	bullet = Sprite::createWithSpriteFrameName("enemybullets_06.png");
	bullet->setPosition(position.x, position.y + 10);
	bullet->setTag(ActivationBulletTag);

	bulletPhysics = PhysicsBody::createCircle(bullet->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
	bulletPhysics->setContactTestBitmask(true);
	bulletPhysics->setCollisionBitmask(0);
	bullet->addComponent(bulletPhysics);

	scene->addChild(bullet, -1 * bullet->getPosition().y);

	bulletShadow = Sprite::create("Player/shadow.png");
	//bulletShadow->setPosition(bullet->getPosition().x, bullet->getPosition().y - height);
	bulletShadow->setPosition(bullet->getPosition().x, bullet->getPosition().y);
	bulletShadow->setScale(0.1f);
	bulletShadow->setOpacity(100);
	bulletShadow->setTag(ActivationBulletTag);

	bulletShadowPhysics = PhysicsBody::createCircle(bulletShadow->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
	bulletShadowPhysics->setPositionOffset(Vec2(0, 0));
	bulletShadowPhysics->setContactTestBitmask(true);

	if (height >= 20)
		bulletShadowPhysics->setCollisionBitmask(13); // 높은총알
	else
		bulletShadowPhysics->setCollisionBitmask(9); // 일반 총알

	bulletShadow->addComponent(bulletShadowPhysics);

	scene->addChild(bulletShadow, -2);

	eraseAction1 = Sequence::create(CallFunc::create(CC_CALLBACK_0(MonsterBullet::ErasePhysicsBody, this)),
		CallFunc::create(CC_CALLBACK_0(MonsterBullet::PlayBulletEraseSound, this)), BulletEraseAnimate,
		CallFunc::create(CC_CALLBACK_0(MonsterBullet::EraseBulletVec, this)), RemoveSelf::create(), nullptr);
	eraseAction1->setTag(1);
	eraseAction1->retain();
	eraseAction2 = Sequence::create(CallFunc::create(CC_CALLBACK_0(MonsterBullet::PlayBulletEraseSound, this)), BulletEraseAnimate, CallFunc::create(CC_CALLBACK_0(MonsterBullet::EraseBulletVec, this)), RemoveSelf::create(), nullptr);
	eraseAction2->setTag(2);
	eraseAction2->retain();
	eraseAction3 = Sequence::create(JumpBy::create(height / 30,Vec2(0,0), height, 1), CallFunc::create(CC_CALLBACK_0(MonsterBullet::ChangeTag,this)) ,nullptr);
	eraseAction3->setTag(3);
	eraseAction3->retain();
	


	Player->monsterBulletVec.push_back(this);

	_impulseX = ImpulseX;
	_impulseY = ImpulseY;
	_height = height;

	bullet->runAction(eraseAction3);

	MoveBullet();
}

void MonsterBullet::tick()
{
	RangeCount();
	EraseBullet();
	SetZorder();
}

void MonsterBullet::MoveBullet()
{
	bulletPhysics->applyImpulse(Vec2(_impulseX, _impulseY));
	bulletShadowPhysics->applyImpulse(Vec2(_impulseX, _impulseY));
}

void MonsterBullet::EraseBullet()
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

void MonsterBullet::RangeCount()
{

}

void MonsterBullet::ErasePhysicsBody()
{
	bulletPhysics->removeFromWorld();
	bulletShadowPhysics->removeFromWorld();
	bulletShadow->setVisible(false);
}

void MonsterBullet::EraseBulletVec()
{
	bulletShadow->setTag(EraseOnVec);
}

void MonsterBullet::PlayBulletEraseSound()
{
}

void MonsterBullet::SetZorder()
{
	if (bulletShadow->getTag() == ActivationBulletTag)
	{
		bulletShadow->setLocalZOrder(bulletShadow->getPositionY() * -1 + _height);
		bullet->setLocalZOrder(bullet->getPositionY() * -1 + _height);
	}
}

void MonsterBullet::ChangeTag()
{
	log("체인지태그");
	bulletShadow->setTag(EraseBulletTag2);
}
