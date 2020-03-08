#include "ShopMaster.h"

void ShopMaster::CreateObject(Scene * scene, Vec2 position, int index)
{
	ObjectSprite = Sprite::create("Shop/Shop_master_03.png");
	ObjectSprite->setPosition(position);
	ObjectSprite->setTag(ObjectIdle);

	ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize(), PhysicsMaterial(0, 0, 0));
	ObjectPhysics->setDynamic(false);
	ObjectPhysics->setCollisionBitmask(2);
	ObjectPhysics->setContactTestBitmask(true);
	ObjectSprite->setPhysicsBody(ObjectPhysics);

	scene->addChild(ObjectSprite, -ObjectSprite->getPosition().y);

	ObjectSprite->setLocalZOrder(ObjectSprite->getPositionY() * -1);

	ObjectHp = 1;

	Player->objectVec.push_back(this);

	_index = index;
	_scene = scene;
	_position = position;
}

void ShopMaster::tick()
{
	if (ObjectSprite->getTag() == ObjectHit)
	{
		ObjectSprite->setTag(ObjectIdle);
	}

	if (ObjectSprite->getTag() == ObjectCollisionBomb)
	{
		ObjectHp = 0;
	}


	if (ObjectHp == 0)
	{
		ObjectSprite->setVisible(false);
		ObjectSprite->setTag(ObjectErase);
		ObjectSprite->setLocalZOrder(ObjectSprite->getLocalZOrder() - 5000);
		ObjectPhysics->removeFromWorld();

		if (RGI->getPercentage(1.0f))
		{
			auto randomIndex = RGI->getRandomNumberWithRange(1, 4);

			switch (randomIndex)
			{
			case 1:
			{
				coinMaker = new Coin(_scene, _position);
			}
			break;
			case 2:
			{
				keyMaker = new Key(_scene, _position);
			}
			break;
			case 3:
			{
				bombMaker = new Bomb(_scene, _position);
			}
			break;
			case 4:
			{
				heartMaker = new Heart(_scene, _position);
			}
			break;
			default:
				break;
			}
		}
	}

}
