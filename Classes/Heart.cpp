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


	

	Player->itemBaseVec.push_back(this);
}

void Heart::tick()
{
	SetZorder();
	EraseItem();
}

void Heart::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void Heart::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		
		itemSprite->runAction(RemoveSelf::create());
		itemPhysics->removeFromWorld();
		Player->setHp(Player->getHp() + 2);
	}
}
