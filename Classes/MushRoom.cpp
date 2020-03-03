#include "MushRoom.h"

void MushRoom::CreateObject(Scene* scene, Vec2 position, int index)
{
	switch (index)
	{
	case 1:
	{
		ObjectSprite = Sprite::create("Object/Rock_Cave/rocks_caves_07.png");
	}
	break;
	case 2:
	{
		ObjectSprite = Sprite::create("Object/Rock_Cave/rocks_caves_11.png");
	}
	break;
	case 3:
	{
		ObjectSprite = Sprite::create("Object/Rock_Cave/rocks_caves_14.png");
	}
	break;
	case 16:
	{
		ObjectSprite = Sprite::create("Object/Rock_Cave/rocks_caves_15.png");
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

void MushRoom::tick()
{
	if (ObjectSprite->getTag() == ObjectCollisionBomb)
	{
		ObjectHp = 0;
	}

	if (ObjectHp == 0)
	{
		if (_index == 4)
			return;

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
	}
}
