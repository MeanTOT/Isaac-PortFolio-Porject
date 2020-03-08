#include "Pill.h"

Pill::Pill(Scene * scene, Vec2 position)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ITEMS/PickUp_Pills.plist");

	auto randomIndex = RGI->getRandomNumberWithRange(1, 9);

	switch (randomIndex)
	{
	case 1:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_01.png");
		break;
	case 2:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_02.png");
		break;
	case 3:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_03.png");
		break;
	case 4:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_04.png");
		break;
	case 5:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_05.png");
		break;
	case 6:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_06.png");
		break;
	case 7:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_07.png");
		break;
	case 8:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_08.png");
		break;
	case 9:
		itemSprite = Sprite::createWithSpriteFrameName("pickup_pill_09.png");
		break;
	default:
		break;
	}

	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 8, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setCollisionBitmask(11);
	itemPhysics->setLinearDamping(1);
	itemSprite->addComponent(itemPhysics);

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y);

	ItemSummonAnimation(itemSprite);

	Player->itemBaseVec.push_back(this);
}

void Pill::tick()
{
	SetZorder();
	EraseItem();
}

void Pill::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void Pill::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		itemPhysics->removeFromWorld();
		itemSprite->runAction(Sequence::createWithTwoActions(DelayTime::create(2.f), RemoveSelf::create()));
		itemSprite->setVisible(false);

		Player->doGetItemAction(PillsItem);
	}
}
