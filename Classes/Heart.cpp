#include "Heart.h"

Heart::Heart(Scene * scene, Vec2 position)
{
	itemSprite = Sprite::create("ITEMS/pickup_heart_01.png");
	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 4, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setCollisionBitmask(11);
	itemPhysics->setLinearDamping(1);
	itemSprite->addComponent(itemPhysics);

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y);;

	ItemSummonAnimation(itemSprite);

	Player->itemBaseVec.push_back(this);
}

void Heart::tick()
{
	SetZorder();
	EraseItem();

	if (!itemSprite->getNumberOfRunningActions())
		itemSprite->runAction(Sequence::create(ScaleTo::create(0.1f, 0.8f, 1.2f), ScaleTo::create(0.1f, 1.2f, 0.8f), ScaleTo::create(0.1f, 1.0f),DelayTime::create(0.5f), nullptr));
}

void Heart::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void Heart::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		if (Player->getHp() < Player->getMaxHp())
		{
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
