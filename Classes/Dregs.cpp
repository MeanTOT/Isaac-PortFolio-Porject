#include "Dregs.h"

Dregs::Dregs(Scene * scene, Vec2 position, ObjectName objectname, int zoder)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Object/Dregs/PoopDregs1.plist");

	switch (objectname)
	{
	case ObjectRock:
	{
		dregs[0] = Sprite::create("Object/Rock/rocks_basement_Dregs_01.png");
		dregs[1] = Sprite::create("Object/Rock/rocks_basement_Dregs_02.png");
		dregs[2] = Sprite::create("Object/Rock/rocks_basement_Dregs_03.png");
		dregs[3] = Sprite::create("Object/Rock/rocks_basement_Dregs_04.png");
		
		for (int i = 0; i < 4; i++)
		{
			dregs[i]->setPosition(position.x, position.y);
			scene->addChild(dregs[i], zoder);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 50);

			dregs[i]->runAction(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1));
		}
	}
		break;
	case ObjectFire:
	{

	}
		break;
	case ObjectPoop:
	{
		dregs[0] = Sprite::createWithSpriteFrameName("poopDregs1_01.png");
		dregs[1] = Sprite::createWithSpriteFrameName("poopDregs1_02.png");
		dregs[2] = Sprite::createWithSpriteFrameName("poopDregs1_03.png");
		dregs[3] = Sprite::createWithSpriteFrameName("poopDregs1_04.png");
		dregs[4] = Sprite::createWithSpriteFrameName("poopDregs1_05.png");
		dregs[5] = Sprite::createWithSpriteFrameName("poopDregs1_06.png");
		dregs[6] = Sprite::createWithSpriteFrameName("poopDregs1_07.png");
		dregs[7] = Sprite::createWithSpriteFrameName("poopDregs1_08.png");

		for (int i = 0; i < 8; i++)
		{
			randomAddChild[i] = RGI->getPercentage(0.5f);

			if (!randomAddChild[i])
				continue;

			dregs[i]->setPosition(position.x, position.y);
			scene->addChild(dregs[i], zoder);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 50);

			dregs[i]->runAction(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1));
		}
	}		 
		break;
	default:
		break;
	}

}

Dregs::~Dregs()
{
}
