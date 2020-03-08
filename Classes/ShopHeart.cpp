#include "ShopHeart.h"

ShopHeart::ShopHeart(Scene * scene, Vec2 position)
{
	itemSprite = Sprite::create("ITEMS/pickup_heart_01.png");
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

void ShopHeart::tick()
{
	SetZorder();
	EraseItem();
}

void ShopHeart::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void ShopHeart::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		if (Player->getHp() < Player->getMaxHp() && Player->getCoinCount() >= 5)
		{
			Player->setCoinCount(Player->getCoinCount() - 5);

			itemSprite->runAction(RemoveSelf::create());
			itemPhysics->removeFromWorld();
			Player->setHp(Player->getHp() + 2);
		}
		else
		{
			itemSprite->setTag(ItemIdle);
		}
	}
}
