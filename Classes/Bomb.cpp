#include "Bomb.h"

Bomb::Bomb(Scene * scene, Vec2 position)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ITEMS/BOMBS.plist");

	itemSprite = Sprite::createWithSpriteFrameName("Bombs_01.png");
	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setCollisionBitmask(11);
	itemPhysics->setLinearDamping(1);
	itemSprite->addComponent(itemPhysics);

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y);;

	Player->itemBaseVec.push_back(this);
}

void Bomb::tick()
{
	SetZorder();
	EraseItem();
}

void Bomb::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void Bomb::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		SMI->PlayBombPickUp();
		itemSprite->runAction(RemoveSelf::create());
		itemPhysics->removeFromWorld();
		Player->setBombCount(Player->getBombCount() + 1);
	}
}
