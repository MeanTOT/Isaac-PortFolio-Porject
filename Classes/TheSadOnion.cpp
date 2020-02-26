#include "TheSadOnion.h"

TheSadOnion::TheSadOnion(Scene * scene, Vec2 position)
{
	cache = SpriteFrameCache::getInstance();

	itemSprite = Sprite::create("ITEMS/collectibles_001_thesadonion.png");
	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 1.5f, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setDynamic(false);
	itemPhysics->setCollisionBitmask(12);
	itemSprite->addComponent(itemPhysics);

	act1 = EaseInOut::create(MoveBy::create(0.5f, Vec2(0, 7)), 1.5f);
	act1->retain();

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y + 10);

	Player->itemBaseVec.push_back(this);
}

void TheSadOnion::tick()
{
	SetZorder();
	EraseItem();

	if (!itemSprite->getNumberOfRunningActions())
	{
		itemSprite->runAction(Sequence::create(act1, act1->reverse(), nullptr));
	}
}

void TheSadOnion::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1 + 100);
}

void TheSadOnion::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		itemPhysics->removeFromWorld();
		itemSprite->setVisible(false);
		itemSprite->runAction(Sequence::createWithTwoActions(DelayTime::create(3), RemoveSelf::create()));

		Player->doGetItemAction(TheSadOnionITEM);
	}
}
