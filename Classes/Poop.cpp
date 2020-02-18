#include "Poop.h"

void Poop::CreateObject(Scene * scene, Vec2 position, int index)
{
	switch (index)
	{
	case 1:
	{
		ObjectSprite = Sprite::create("Object/Poop/grid_poop_01.png");
	}
	break;
	case 2:
	{
		ObjectSprite = Sprite::create("Object/Poop/grid_poop_06.png");
	}
	break;
	case 3:
	{
		ObjectSprite = Sprite::create("Object/Poop/grid_poop_11.png");
	}
	break;
	case 4:
	{
		ObjectSprite = Sprite::create("Object/Poop/grid_poop_16.png");
	}
	break;
	case 5:
	{
		ObjectSprite = Sprite::create("Object/Poop/grid_poop_21.png");
	}
	break;
	default:
		break;
	}

	ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize(), PhysicsMaterial(0, 0, 0));
	ObjectPhysics->setDynamic(false);
	ObjectPhysics->setCollisionBitmask(2);
	ObjectPhysics->setContactTestBitmask(true);
	ObjectSprite->setPhysicsBody(ObjectPhysics);
	ObjectSprite->setPosition(position);
	ObjectSprite->setTag(ObjectIdle);

	scene->addChild(ObjectSprite, -ObjectSprite->getPosition().y);

	ObjectSprite->setZOrder(ObjectSprite->getPositionY() * -1);

	ObjectHp = 4;
	_index = index;

	Player->objectVec.push_back(this);
}

void Poop::tick()
{
	if (ObjectSprite->getTag() == ObjectHit)
	{
		ObjectHp -= 1;

		ObjectSprite->setTag(ObjectIdle);
	}

	if (ObjectSprite->getTag() == ObjectCollisionBomb)
	{
		ObjectHp = 0;
	}

	if (_index == 1)
	{
		if (ObjectHp == 4)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_01.png");
		}
		if (ObjectHp == 3)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_02.png");
		}
		if (ObjectHp == 2)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_03.png");
		}
		if (ObjectHp == 1)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_04.png");
		}
		if (ObjectHp == 0)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_05.png");
			ObjectSprite->setTag(ObjectErase);
			ObjectSprite->setZOrder(ObjectSprite->getZOrder() - 5000);
			ObjectPhysics->removeFromWorld();
		}
	}
	if (_index == 2)
	{
		if (ObjectHp == 4)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_06.png");
		}
		if (ObjectHp == 3)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_07.png");
		}
		if (ObjectHp == 2)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_08.png");
		}
		if (ObjectHp == 1)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_09.png");
		}
		if (ObjectHp == 0)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_10.png");
			ObjectSprite->setTag(ObjectErase);
			ObjectSprite->setZOrder(ObjectSprite->getZOrder() - 5000);
			ObjectPhysics->removeFromWorld();
		}
	}
	if (_index == 3)
	{
		if (ObjectHp == 4)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_11.png");
		}
		if (ObjectHp == 3)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_12.png");
		}
		if (ObjectHp == 2)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_13.png");
		}
		if (ObjectHp == 1)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_14.png");
		}
		if (ObjectHp == 0)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_15.png");
			ObjectSprite->setTag(ObjectErase);
			ObjectSprite->setZOrder(ObjectSprite->getZOrder() - 5000);
			ObjectPhysics->removeFromWorld();
		}
	}
	if (_index == 4)
	{
		if (ObjectHp == 4)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_16.png");
		}
		if (ObjectHp == 3)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_17.png");
		}
		if (ObjectHp == 2)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_18.png");
		}
		if (ObjectHp == 1)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_19.png");
		}
		if (ObjectHp == 0)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_20.png");
			ObjectSprite->setTag(ObjectErase);
			ObjectSprite->setZOrder(ObjectSprite->getZOrder() - 5000);
			ObjectPhysics->removeFromWorld();
		}
	}
	if (_index == 5)
	{
		if (ObjectHp == 4)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_21.png");
		}
		if (ObjectHp == 3)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_22.png");
		}
		if (ObjectHp == 2)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_23.png");
		}
		if (ObjectHp == 1)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_24.png");
		}
		if (ObjectHp == 0)
		{
			ObjectSprite->setTexture("Object/Poop/grid_poop_25.png");
			ObjectSprite->setTag(ObjectErase);
			ObjectSprite->setZOrder(ObjectSprite->getZOrder() - 5000);
			ObjectPhysics->removeFromWorld();
		}
	}
}
