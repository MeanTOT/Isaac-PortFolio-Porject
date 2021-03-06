#include "Rocks.h"

void Rocks::CreateObject(Scene* scene, Vec2 position, int index)
{
	switch (index)
	{
	case 1:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_01.png");
	}
	break;
	case 2:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_02.png");
	}
	break;
	case 3:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_03.png");
	}
	break;
	case 4:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_05.png");
	}
	break;
	case 5:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_06.png");
	}
	break;
	case 6:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_09.png");
	}
	break;
	case 7:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_10.png");
	}
	break;
	case 8:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_11.png");
	}
	break;
	case 9:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_12.png");
	}
	break;
	case 10:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_13.png");
	}
	break;
	case 11:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_14.png");
	}
	break;
	case 12:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_15.png");
	}
	break;
	case 13:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_17.png");
	}
	break;
	case 14:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_19.png");
	}
	break;
	case 15:
	{
		ObjectSprite = Sprite::create("Object/Rock/rocks_basement_07.png");
	}
	break;
	case 16:
	{
		ObjectSprite = Sprite::create("Object/Rock_Cave/rocks_caves_01.png");
	}
	break;
	case 17:
	{
		ObjectSprite = Sprite::create("Object/Rock_Cave/rocks_caves_02.png");
	}
	break;
	case 18:
	{
		ObjectSprite = Sprite::create("Object/Rock_Cave/rocks_caves_03.png");
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

	scene->addChild(ObjectSprite, -1 * ObjectSprite->getPosition().y);

	ObjectHp = 1;

	Player->objectVec.push_back(this);

	_index = index;
	_scene = scene;
	_position = position;
}

void Rocks::tick()
{
	if (ObjectSprite->getTag() == ObjectCollisionBomb)
	{
		ObjectHp = 0;
	}

	if (ObjectHp == 0)
	{
		if (_index == 4)
			return;

		if (_index == 5)
		{
			this->RandomItemDropUnconditional();
			this->RandomItemDropUnconditional();
			this->RandomItemDropUnconditional();
			this->RandomItemDropUnconditional();
		}

		ObjectSprite->setTexture("Object/Rock/rocks_basement_04.png");
		ObjectSprite->setTag(ObjectErase);
		ObjectSprite->setLocalZOrder(ObjectSprite->getLocalZOrder() - 5000);
		ObjectSprite->setVisible(false);

		ObjectPhysics->removeFromWorld();

		_dregs = new Dregs(_scene, _position, ObjectRock, ObjectSprite->getLocalZOrder());
		
		this->RandomItemDrop();

		log("%f", Player->getItemInvLuck());

		auto randomindex = RGI->getRandomNumberWithRange(1, 3);

		switch (randomindex)
		{
		case 1:
			SMI->PlayRockCrumble1();
			break;
		case 2:
			SMI->PlayRockCrumble2();
			break;
		case 3:
			SMI->PlayRockCrumble3();
			break;
		default:
			break;
		}


		if (_index == 6)
		{
			_explosion = new Explosion(_scene, _position, BaseMentBomb);
		}
	}
}
