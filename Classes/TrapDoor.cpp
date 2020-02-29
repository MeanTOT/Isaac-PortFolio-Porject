#include "TrapDoor.h"

void TrapDoor::CreateObject(Scene* scene, Vec2 position, int index)
{
	Obcache = SpriteFrameCache::getInstance();
	Obcache->addSpriteFramesWithFile("MapImage/DoorTrapDoor.plist");

	ObjectSprite = Sprite::createWithSpriteFrameName("Door_TrapDoor_01.png");
	//ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize(), PhysicsMaterial(0, 0, 0));
	//ObjectPhysics->setDynamic(false);
	//ObjectPhysics->setCollisionBitmask(2);
	//ObjectPhysics->setContactTestBitmask(true);
	//ObjectSprite->setPhysicsBody(ObjectPhysics);
	ObjectSprite->setPosition(position);
	ObjectSprite->setTag(ObjectIdle);

	scene->addChild(ObjectSprite, -1 * ObjectSprite->getPosition().y - 500);

	Player->objectVec.push_back(this);

	_scene = scene;
	_position = position;
}

void TrapDoor::tick()
{
	if (ObjectSprite->getBoundingBox().containsPoint(Player->getIsaacBody()->getPosition()))
	{
		Player->getIsaacBody()->setVisible(false);
		Player->getIsaacVirtualBody()->setVisible(true);

		Player->getIsaacPysicBody()->applyImpulse(Vect(ObjectSprite->getPosition() - 
			Vec2(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y - 15)));

		if (!Player->getIsaacVirtualBody()->getNumberOfRunningActions())
		{
			Player->getIsaacVirtualBody()->runAction(Sequence::create(Player->getIsaacGoToNextDoorAnimate(),
				CallFunc::create(CC_CALLBACK_0(TrapDoor::SceneChange,this)), DelayTime::create(5) ,nullptr));
		}
	}
}

void TrapDoor::SceneChange()
{
	Player->setSceneChange(true);
}
