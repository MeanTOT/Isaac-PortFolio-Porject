#include "ShopItem_BloodOfTheMarTyr.h"

ShopItem_BloodOfTheMarTyr::ShopItem_BloodOfTheMarTyr(Scene * scene, Vec2 position)
{
	cache = SpriteFrameCache::getInstance();

	itemSprite = Sprite::create("ITEMS/collectibles_007_bloodofthemartyr.png");
	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 3.0f, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setDynamic(false);
	itemPhysics->setCollisionBitmask(17);
	itemSprite->addComponent(itemPhysics);

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y + 10);

	Player->itemBaseVec.push_back(this);
}

void ShopItem_BloodOfTheMarTyr::tick()
{
	SetZorder();
	EraseItem();
}

void ShopItem_BloodOfTheMarTyr::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1 + 100);
}

void ShopItem_BloodOfTheMarTyr::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		if (Player->getCoinCount() >= 15)
		{
			itemPhysics->removeFromWorld();
			itemSprite->setVisible(false);
			itemSprite->runAction(Sequence::createWithTwoActions(DelayTime::create(3), RemoveSelf::create()));

			Player->doGetItemAction(BloodOfTheMarTyrITEM);
		}
		else
		{
			itemSprite->setTag(ItemIdle);
		}
	}
	
}
