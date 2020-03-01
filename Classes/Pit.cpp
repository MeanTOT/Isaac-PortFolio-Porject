#include "Pit.h"

void Pit::CreateObject(Scene* scene, Vec2 position, int index)
{
	switch (index)
	{
	case 1:
	{
		ObjectSprite = Sprite::create("Object/Pit/grid_pit_catacombs_07.png");
	}
	break;
	case 2:
	{
		ObjectSprite = Sprite::create("Object/Pit/grid_pit_catacombs_07.png");
	}
	break;
	default:
		break;
	}

	ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize(), PhysicsMaterial(0, 0, 0));
	ObjectPhysics->setDynamic(false);
	ObjectPhysics->setCollisionBitmask(14);
	ObjectPhysics->setContactTestBitmask(true);
	ObjectSprite->setPhysicsBody(ObjectPhysics);
	ObjectSprite->setPosition(position);
	ObjectSprite->setTag(ObjectIdle);

	scene->addChild(ObjectSprite, -1 * ObjectSprite->getPosition().y - 500);

	Player->objectVec.push_back(this);

	_index = index;
	_scene = scene;
	_position = position;
}

void Pit::tick()
{

}
