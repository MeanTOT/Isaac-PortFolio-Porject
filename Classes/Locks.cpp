#include "Locks.h"

void Locks::CreateObject(Scene* scene, Vec2 position, int index)
{
	Obcache = SpriteFrameCache::getInstance();
	Obcache->addSpriteFramesWithFile("Object/Locks/Locks.plist");

	ObjectSprite = Sprite::createWithSpriteFrameName("grid_locks_01.png");
	ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize(), PhysicsMaterial(0, 0, 0));
	ObjectPhysics->setDynamic(false);
	ObjectPhysics->setCollisionBitmask(2);
	ObjectPhysics->setContactTestBitmask(true);
	ObjectSprite->setPhysicsBody(ObjectPhysics);
	ObjectSprite->setPosition(position);
	ObjectSprite->setTag(ObjectIdle);

	scene->addChild(ObjectSprite, -1 * ObjectSprite->getPosition().y);

	ObjectAnimation = Animation::create();
	ObjectAnimation->setDelayPerUnit(0.07f);
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_01.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_02.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_03.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_04.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_05.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_06.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_07.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_08.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_09.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_10.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_11.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_12.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_13.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_14.png"));
	ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("grid_locks_15.png"));
	ObjectAnimate = Animate::create(ObjectAnimation);
	ObjectAnimate->retain();

	ObjectHp = 1;

	Player->objectVec.push_back(this);

	_index = index;
	_scene = scene;
	_position = position;
}

void Locks::tick()
{
	if (ObjectSprite->getTag() == ObjectIdle)
	{
		if (ObjectSprite->getBoundingBox().intersectsRect(Player->getIsaacBody()->getBoundingBox()))
		{
			if (Player->getKeyCount() >= 1)
			{
				Player->setKeyCount(Player->getKeyCount() - 1);

				SMI->PlayLockBreak();

				ObjectSprite->runAction(Sequence::createWithTwoActions(ObjectAnimate, CallFunc::create(CC_CALLBACK_0(Locks::RemovePhysicsBody, this))));

				ObjectSprite->setTag(ObjectErase);
			}
		}
	}
}

void Locks::RemovePhysicsBody()
{
	ObjectPhysics->removeFromWorld();
}

