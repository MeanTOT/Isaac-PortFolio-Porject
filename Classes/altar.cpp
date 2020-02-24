#include "altar.h"

void altar::CreateObject(Scene* scene, Vec2 position, int index)
{
	ObjectSprite = Sprite::create("ITEMS/altar.png");

	ObjectPhysics = PhysicsBody::createBox(ObjectSprite->getContentSize(), PhysicsMaterial(0, 0, 0));
	ObjectPhysics->setDynamic(false);
	ObjectPhysics->setCollisionBitmask(2);
	ObjectPhysics->setContactTestBitmask(true);

	ObjectSprite->setPhysicsBody(ObjectPhysics);
	ObjectSprite->setPosition(position);
	ObjectSprite->setTag(ObjectIdle);

	scene->addChild(ObjectSprite, -1 * ObjectSprite->getPosition().y);

	ObjectHp = 0;

	Player->objectVec.push_back(this);

	_index = index;
	_scene = scene;
	_position = position;
}

void altar::tick()
{
	
}
