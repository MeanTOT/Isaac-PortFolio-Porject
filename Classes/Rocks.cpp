#include "Rocks.h"

Rocks::Rocks()
{

}

Rocks::~Rocks()
{
}

void Rocks::CreateRockBaseMent(Scene* scene, Vec2 position, int index)
{
	switch (index)
	{
	case 1:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_01.png");
	}
	break;
	case 2:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_02.png");
	}
	break;
	case 3:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_03.png");
	}
	break;
	case 4:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_05.png");
	}
	break;
	case 5:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_06.png");
	}
	break;
	case 6:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_09.png");
	}
	break;
	case 7:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_10.png");
	}
	break;
	case 8:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_11.png");
	}
	break;
	case 9:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_12.png");
	}
	break;
	case 10:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_13.png");
	}
	break;
	case 11:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_14.png");
	}
	break;
	case 12:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_15.png");
	}
	break;
	case 13:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_17.png");
	}
	break;
	case 14:
	{
		Rock_BaseMent = Sprite::create("Object/Rock/rocks_basement_19.png");
	}
	break;
	default:
		break;
	}

	


	Rock_BaseMentPhysics = PhysicsBody::createBox(Rock_BaseMent->getContentSize(), PhysicsMaterial(0, 0, 0));
	Rock_BaseMentPhysics->setDynamic(false);
	Rock_BaseMentPhysics->setCollisionBitmask(2);
	Rock_BaseMentPhysics->setContactTestBitmask(true);
	Rock_BaseMent->setPhysicsBody(Rock_BaseMentPhysics);
	Rock_BaseMent->setPosition(position);

	scene->addChild(Rock_BaseMent, -Rock_BaseMent->getPosition().y);
}
