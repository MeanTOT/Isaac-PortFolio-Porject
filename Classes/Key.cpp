#include "Key.h"

Key::Key(Scene * scene, Vec2 position)
{
	itemSprite = Sprite::create("ITEMS/pickup_key.png");
	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 4, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setCollisionBitmask(11);
	itemPhysics->setLinearDamping(1);
	itemSprite->addComponent(itemPhysics);

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y);;

	ItemSummonAnimation(itemSprite);

	SMI->PlayKeyDrop();

	Player->itemBaseVec.push_back(this);
}

void Key::tick()
{
	SetZorder();
	EraseItem();
}

void Key::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void Key::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		SMI->PlayKeyPickUp();
		itemSprite->runAction(RemoveSelf::create());
		itemPhysics->removeFromWorld();
		Player->setKeyCount(Player->getKeyCount() + 1);
	}
}
