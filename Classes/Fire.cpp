#include "Fire.h"

void Fire::CreateObject(Scene * scene, Vec2 position, int index)
{
	if (index == 1)
	{
		Obcache = SpriteFrameCache::getInstance();
		Obcache->addSpriteFramesWithFile("Object/Fire/FirePlace_basic.plist");
		Obcache->addSpriteFramesWithFile("Object/Fire/Effect_poopspawn.plist");

		ObjectAnimation = Animation::create();
		ObjectAnimation->setDelayPerUnit(0.08f);
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_01.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_02.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_03.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_04.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_05.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_06.png"));
		ObjectAnimate = Animate::create(ObjectAnimation);
		ObjectAnimate->retain();

		ObjectSprite = Sprite::createWithSpriteFrameName("grid_fireplace_01.png");

		ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize() / 1.5f, PhysicsMaterial(0, 0, 0));
		ObjectPhysics->setDynamic(false);
		ObjectPhysics->setCollisionBitmask(8);
		ObjectPhysics->setContactTestBitmask(true);

		ObjectSprite->setPhysicsBody(ObjectPhysics);
		ObjectSprite->setPosition(position);
		ObjectSprite->setTag(ObjectIdle);

		scene->addChild(ObjectSprite, -ObjectSprite->getPosition().y);

		fire = Sprite::createWithSpriteFrameName("effect_005_fire_01.png");
		fire->setOpacity(200);
		fire->setAnchorPoint({ 0.5,0 });
		fire->setPosition(position.x, position.y - 5);


		scene->addChild(fire);


		ObjectSprite->setLocalZOrder(ObjectSprite->getPositionY() * -1);
		fire->setLocalZOrder(ObjectSprite->getPositionY() * -1 + 1);

		ObjectHp = 3;
	}
	if (index == 2)
	{
		Obcache = SpriteFrameCache::getInstance();
		Obcache->addSpriteFramesWithFile("Object/Fire/FirePlace_Blue.plist");

		ObjectAnimation = Animation::create();
		ObjectAnimation->setDelayPerUnit(0.08f);
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_blue_01.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_blue_02.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_blue_03.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_blue_04.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_blue_05.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_blue_06.png"));
		ObjectAnimate = Animate::create(ObjectAnimation);
		ObjectAnimate->retain();

		ObjectSprite = Sprite::createWithSpriteFrameName("grid_fireplace_blue_01.png");

		ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize() / 2, PhysicsMaterial(0, 0, 0));
		ObjectPhysics->setDynamic(false);
		ObjectPhysics->setCollisionBitmask(8);
		ObjectPhysics->setContactTestBitmask(true);

		ObjectSprite->setPhysicsBody(ObjectPhysics);
		ObjectSprite->setPosition(position);
		ObjectSprite->setTag(ObjectIdle);

		scene->addChild(ObjectSprite, -ObjectSprite->getPosition().y);

		fire = Sprite::createWithSpriteFrameName("effect_005_fire_blue_01.png");
		fire->setOpacity(200);
		fire->setAnchorPoint({ 0.5,0 });
		fire->setPosition(position.x, position.y - 5);


		scene->addChild(fire);


		ObjectSprite->setLocalZOrder(ObjectSprite->getPositionY() * -1);
		fire->setLocalZOrder(ObjectSprite->getPositionY() * -1 + 1);

		ObjectHp = 3;
	}
	if (index == 3)
	{
		Obcache = SpriteFrameCache::getInstance();
		Obcache->addSpriteFramesWithFile("Object/Fire/FirePlace_Purple.plist");

		ObjectAnimation = Animation::create();
		ObjectAnimation->setDelayPerUnit(0.08f);
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_purple_01.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_purple_02.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_purple_03.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_purple_04.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_purple_05.png"));
		ObjectAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_005_fire_purple_06.png"));
		ObjectAnimate = Animate::create(ObjectAnimation);
		ObjectAnimate->retain();

		ObjectSprite = Sprite::createWithSpriteFrameName("grid_fireplace_purple_01.png");

		ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize() / 2, PhysicsMaterial(0, 0, 0));
		ObjectPhysics->setDynamic(false);
		ObjectPhysics->setCollisionBitmask(8);
		ObjectPhysics->setContactTestBitmask(true);

		ObjectSprite->setPhysicsBody(ObjectPhysics);
		ObjectSprite->setPosition(position);
		ObjectSprite->setTag(ObjectIdle);

		scene->addChild(ObjectSprite, -ObjectSprite->getPosition().y);

		fire = Sprite::createWithSpriteFrameName("effect_005_fire_purple_01.png");
		fire->setOpacity(200);
		fire->setAnchorPoint({ 0.5,0 });
		fire->setPosition(position.x, position.y - 5);


		scene->addChild(fire);


		ObjectSprite->setLocalZOrder(ObjectSprite->getPositionY() * -1);
		fire->setLocalZOrder(ObjectSprite->getPositionY() * -1 + 1);

		ObjectHp = 3;
	}

	poofAnimation = Animation::create();
	poofAnimation->setDelayPerUnit(0.08f);
	poofAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_poopspawn_01.png"));
	poofAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_poopspawn_02.png"));
	poofAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_poopspawn_03.png"));
	poofAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_poopspawn_04.png"));
	poofAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_poopspawn_05.png"));
	poofAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_poopspawn_06.png"));
	poofAnimation->addSpriteFrame(Obcache->getSpriteFrameByName("effect_poopspawn_07.png"));
	poofAnimate = Animate::create(poofAnimation);
	poofAnimate->retain();

	_index = index;
	_scene = scene;
	_position = position;

	Player->objectVec.push_back(this);
}

void Fire::tick()
{
	if (ObjectSprite->getTag() == ObjectHit)
	{
		ObjectHp -= 1;

		ObjectSprite->setTag(ObjectIdle);
	}

	if (ObjectSprite->getTag() == ObjectCollisionBomb)
	{
		ObjectHp = 0;
	}

	if (ObjectHp == 3)
	{
		fire->setScale(1.0f);
		if (!fire->getNumberOfRunningActions())
		{
			fire->runAction(ObjectAnimate);
		}
	}
	if (ObjectHp == 2)
	{
		fire->setScale(0.8f);
		if (!fire->getNumberOfRunningActions())
		{
			fire->runAction(ObjectAnimate);
		}
	}
	if (ObjectHp == 1)
	{
		fire->setScale(0.6f);
		if (!fire->getNumberOfRunningActions())
		{
			fire->runAction(ObjectAnimate);
		}
	}
	if (ObjectHp <= 0)
	{
		ObjectSprite->setTag(ObjectErase);
		ObjectSprite->setLocalZOrder(ObjectSprite->getLocalZOrder() - 5000);
		ObjectPhysics->removeFromWorld();

		this->RandomItemDrop();

		SMI->PlayOffFire();

		fire->setVisible(false);
		fire->runAction(Sequence::createWithTwoActions(DelayTime::create(2), RemoveSelf::create()));

		poof = Sprite::createWithSpriteFrameName("effect_poopspawn_01.png");
		poof->setPosition(ObjectSprite->getPosition().x, ObjectSprite->getPosition().y + 10);
		_scene->addChild(poof, poof->getPositionY() * -1);

		poof->runAction(Sequence::create(poofAnimate, RemoveSelf::create(), nullptr));

		if (_index == 1)
			ObjectSprite->setSpriteFrame("grid_fireplace_02.png");
		if (_index == 2)
			ObjectSprite->setSpriteFrame("grid_fireplace_blue_02.png");
		if (_index == 3)
			ObjectSprite->setSpriteFrame("grid_fireplace_purple_02.png");
	}
}
