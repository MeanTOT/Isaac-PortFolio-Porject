#include "ShopKey.h"

ShopKey::ShopKey(Scene * scene, Vec2 position)
{
	itemSprite = Sprite::create("ITEMS/pickup_key.png");
	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 4, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setCollisionBitmask(17);
	itemPhysics->setDynamic(false);
	itemSprite->addComponent(itemPhysics);

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y);;

	ItemSummonAnimation(itemSprite);

	Player->itemBaseVec.push_back(this);
}

void ShopKey::tick()
{
	SetZorder();
	EraseItem();
}

void ShopKey::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void ShopKey::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		if (Player->getCoinCount() >= 5)
		{
			Player->setCoinCount(Player->getCoinCount() - 5);

			itemSprite->runAction(RemoveSelf::create());
			itemPhysics->removeFromWorld();
			Player->setKeyCount(Player->getKeyCount() + 1);
		}
		else
		{
			itemSprite->setTag(ItemIdle);
		}
	}
}
