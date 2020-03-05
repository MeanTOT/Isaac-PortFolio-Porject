#include "Bone.h"

Bone::Bone()
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Bullet/Bone_Projectile.plist");
}

void Bone::CreateIsaacBullet(Scene * scene, Vec2 position, float speed, float angle)
{
	auto randomSound = RGI->getRandomNumberWithRange(1, 4);

	switch (randomSound)
	{
	case 1:
	{
		SMI->PlayBloodFire1();
	}
	break;
	case 2:
	{
		SMI->PlayBloodFire2();
	}
	break;
	case 3:
	{
		SMI->PlayBloodFire3();
	}
	break;
	case 4:
	{
		SMI->PlayBloodFire4();
	}
	break;
	default:
		break;
	}

	bullet = Sprite::createWithSpriteFrameName("bone_projectile_01.png");
	bullet->setPosition(position.x, position.y + 10);
	bullet->setTag(ActivationBulletTag);

	bulletPhysics = PhysicsBody::createCircle(bullet->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
	bulletPhysics->setContactTestBitmask(true);
	bulletPhysics->setCollisionBitmask(0);
	bullet->addComponent(bulletPhysics);

	scene->addChild(bullet, -1 * bullet->getPosition().y);

	bulletShadow = Sprite::create("Player/shadow.png");
	bulletShadow->setPosition(bullet->getPosition().x, bullet->getPosition().y - 10);
	bulletShadow->setScale(0.1f);
	bulletShadow->setOpacity(100);
	bulletShadow->setTag(ActivationBulletTag);

	bulletShadowPhysics = PhysicsBody::createCircle(bulletShadow->getContentSize().width / 2, PhysicsMaterial(0, 0, 0));
	bulletShadowPhysics->setPositionOffset(Vec2(0, 0));
	bulletShadowPhysics->setContactTestBitmask(true);
	bulletShadowPhysics->setCollisionBitmask(9);

	bulletShadow->addComponent(bulletShadowPhysics);

	scene->addChild(bulletShadow, -2);


	// 뼈가 날아가는 애니메이션
	BoneThrowAnimation = Animation::create();
	BoneThrowAnimation->setDelayPerUnit(0.05f);
	BoneThrowAnimation->addSpriteFrame(cache->getSpriteFrameByName("bone_projectile_01.png"));
	BoneThrowAnimation->addSpriteFrame(cache->getSpriteFrameByName("bone_projectile_02.png"));
	BoneThrowAnimation->addSpriteFrame(cache->getSpriteFrameByName("bone_projectile_03.png"));
	BoneThrowAnimation->addSpriteFrame(cache->getSpriteFrameByName("bone_projectile_04.png"));
	BoneThrowAnimate = Animate::create(BoneThrowAnimation);
	BoneThrowAnimate->retain();
	BoneThrowAnimate->setTag(1);

	eraseAction1 = Sequence::create(CallFunc::create(CC_CALLBACK_0(Bone::ErasePhysicsBody, this)),
		CallFunc::create(CC_CALLBACK_0(Bone::PlayBulletEraseSound, this)),
		CallFunc::create(CC_CALLBACK_0(Bone::EraseBulletVec, this)), DelayTime::create(2), RemoveSelf::create(), nullptr);
	eraseAction1->setTag(1);
	eraseAction1->retain();
	eraseAction2 = Sequence::create(CallFunc::create(CC_CALLBACK_0(Bone::PlayBulletEraseSound, this)), CallFunc::create(CC_CALLBACK_0(Bone::EraseBulletVec, this)), DelayTime::create(2),
		RemoveSelf::create(), nullptr);
	eraseAction2->setTag(2);
	eraseAction2->retain();

	Player->BoneVec.push_back(this);

	_angle = angle;
	_speed = speed;
	_scene = scene;

	_height = 30;

	MoveBulletForAngle();
}

void Bone::tick()
{
	RangeCount();
	EraseBullet();
	SetZorder();

	if (!bullet->getNumberOfRunningActionsByTag(1))
	{
		bullet->runAction(BoneThrowAnimate);
	}
}

void Bone::MoveBullet()
{
	bulletPhysics->applyImpulse(Vec2(_impulseX, _impulseY));
	bulletShadowPhysics->applyImpulse(Vec2(_impulseX, _impulseY));
}

void Bone::MoveBulletForAngle()
{
	bullet->runAction(MoveBy::create(2.0f, Vec2(cosf(CC_DEGREES_TO_RADIANS(_angle)) * _speed, sinf(CC_DEGREES_TO_RADIANS(_angle)) * _speed)));
	bulletShadow->runAction(MoveBy::create(2.0f, Vec2(cosf(CC_DEGREES_TO_RADIANS(_angle)) * _speed, sinf(CC_DEGREES_TO_RADIANS(_angle)) * _speed)));
}

void Bone::EraseBullet()
{
	if (bulletShadow->getTag() == EraseBulletTag)
	{
		if (!bullet->getNumberOfRunningActionsByTag(2))
		{
			bullet->stopAllActions();

			bullet->runAction(eraseAction2);
			bulletShadow->runAction(Sequence::create(DelayTime::create(5), RemoveSelf::create(), nullptr));

			bullet->setVisible(false);
			bulletShadow->setVisible(false);

			_dregs = new Dregs(_scene, bullet->getPosition(), ObjectBone, bullet->getLocalZOrder());

			ErasePhysicsBody();
		}
	}

	if (bulletShadow->getTag() == EraseBulletTag2)
	{
		if (!bullet->getNumberOfRunningActionsByTag(1))
		{
			bullet->runAction(eraseAction1);
			bulletShadow->runAction(Sequence::create(DelayTime::create(5), RemoveSelf::create(), nullptr));

			bullet->setVisible(false);
			bulletShadow->setVisible(false);

			_dregs = new Dregs(_scene, bullet->getPosition(), ObjectBone, bullet->getLocalZOrder());
		}
	}
}

void Bone::RangeCount()
{

}

void Bone::ErasePhysicsBody()
{
	bulletPhysics->removeFromWorld();
	bulletShadowPhysics->removeFromWorld();
	bulletShadow->setVisible(false);
}

void Bone::EraseBulletVec()
{
	bulletShadow->setTag(EraseOnVec);
}

void Bone::PlayBulletEraseSound()
{
	SMI->PlayTearBlock();
}

void Bone::SetZorder()
{
	if (bulletShadow->getTag() == ActivationBulletTag)
	{
		bulletShadow->setLocalZOrder(bulletShadow->getPositionY() * -1 + (_height / 2));
		bullet->setLocalZOrder(bullet->getPositionY() * -1 + (_height / 2));
	}
}

void Bone::ChangeTag()
{
	bulletShadow->setTag(EraseBulletTag2);
}
