#include "Coin.h"

Coin::Coin(Scene * scene, Vec2 position)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ITEMS/PickupCoin.plist");

	itemSprite = Sprite::createWithSpriteFrameName("pickup_coin_01.png");
	itemSprite->setPosition(position.x, position.y);
	itemSprite->setTag(ItemIdle);

	itemPhysics = PhysicsBody::createCircle(itemSprite->getContentSize().width / 8, PhysicsMaterial(0, 0, 0));
	itemPhysics->setContactTestBitmask(true);
	itemPhysics->setCollisionBitmask(11);
	itemPhysics->setLinearDamping(1);
	itemSprite->addComponent(itemPhysics);

	scene->addChild(itemSprite, -1 * itemSprite->getPosition().y);


	itemAnimation1 = Animation::create();
	itemAnimation1->setDelayPerUnit(0.05f);
	itemAnimation1->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_01.png"));
	itemAnimation1->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_02.png"));
	itemAnimation1->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_03.png"));
	itemAnimation1->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_04.png"));
	itemAnimation1->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_05.png"));
	itemAnimation1->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_06.png"));
	itemAnimation1->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_01.png"));
	itemAnimate1 = Animate::create(itemAnimation1);
	itemAnimate1->retain();

	itemAnimation2 = Animation::create();
	itemAnimation2->setDelayPerUnit(0.08f);
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_08.png"));
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_09.png"));
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_10.png"));
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_11.png"));
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_12.png"));
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_13.png"));
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_14.png"));
	itemAnimation2->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_15.png"));
	itemAnimate2 = Animate::create(itemAnimation2);


	itemAnimation3 = Animation::create();
	itemAnimation3->setDelayPerUnit(0.03f);
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_16.png"));
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_17.png"));
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_18.png"));
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_19.png"));
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_20.png"));
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_21.png"));
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_22.png"));
	itemAnimation3->addSpriteFrame(cache->getSpriteFrameByName("pickup_coin_23.png"));
	itemAnimate3 = Animate::create(itemAnimation3);
	itemAnimate3->retain();


	itemSprite->runAction(itemAnimate2);
	SMI->PlayPennyDrop();

	Player->itemBaseVec.push_back(this);
}

void Coin::tick()
{
	SetZorder();
	EraseItem();

	if (!itemSprite->getNumberOfRunningActions() && itemSprite->getTag() == ItemIdle)
	{
		itemSprite->runAction(Sequence::createWithTwoActions(itemAnimate1, DelayTime::create(1)));
	}
}

void Coin::SetZorder()
{
	itemSprite->setLocalZOrder(itemSprite->getPositionY() * -1);
}

void Coin::EraseItem()
{
	if (itemSprite->getTag() == ItemErase)
	{
		//itemSprite->stopAllActions();
		itemSprite->runAction(Sequence::create(itemAnimate3, RemoveSelf::create(), nullptr));
		itemPhysics->removeFromWorld();
		Player->setCoinCount(Player->getCoinCount() + 1);
		SMI->PlayPennyPickUp();
	}
}
