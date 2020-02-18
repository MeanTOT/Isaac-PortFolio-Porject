#include "Dregs.h"

Dregs::Dregs(Scene * scene, Vec2 position, ObjectName objectname, int zoder)
{
	switch (objectname)
	{
	case ObjectRock:
	{
		auto Dregs1 = Sprite::create("Object/Rock/rocks_basement_Dregs_01.png");
		Dregs1->setPosition(position.x + Player->getIsaacPysicBody()->getPositionOffset().x, position.y + Player->getIsaacPysicBody()->getPositionOffset().y);
		scene->addChild(Dregs1, zoder - 5000);

		auto Dregs2 = Sprite::create("Object/Rock/rocks_basement_Dregs_02.png");
		Dregs2->setPosition(position.x + Player->getIsaacPysicBody()->getPositionOffset().x, position.y + Player->getIsaacPysicBody()->getPositionOffset().y);
		scene->addChild(Dregs2, zoder - 5000);

		auto Dregs3 = Sprite::create("Object/Rock/rocks_basement_Dregs_03.png");
		Dregs3->setPosition(position.x + Player->getIsaacPysicBody()->getPositionOffset().x, position.y + Player->getIsaacPysicBody()->getPositionOffset().y);
		scene->addChild(Dregs3, zoder - 5000);

		auto Dregs4 = Sprite::create("Object/Rock/rocks_basement_Dregs_04.png");
		Dregs4->setPosition(position.x + Player->getIsaacPysicBody()->getPositionOffset().x, position.y + Player->getIsaacPysicBody()->getPositionOffset().y);
		scene->addChild(Dregs4, zoder - 5000);

		auto randomPosX1 = RGI->getRandomNumberWithRange(-25, 25);
		auto randomPosY1 = RGI->getRandomNumberWithRange(-25, 25);
		auto randomPosX2 = RGI->getRandomNumberWithRange(-25, 25);
		auto randomPosY2 = RGI->getRandomNumberWithRange(-25, 25);
		auto randomPosX3 = RGI->getRandomNumberWithRange(-25, 25);
		auto randomPosY3 = RGI->getRandomNumberWithRange(-25, 25);
		auto randomPosX4 = RGI->getRandomNumberWithRange(-25, 25);
		auto randomPosY4 = RGI->getRandomNumberWithRange(-25, 25);

		auto randomHeight1 = RGI->getRandomNumberWithRange(0, 50);
		auto randomHeight2 = RGI->getRandomNumberWithRange(0, 50);
		auto randomHeight3 = RGI->getRandomNumberWithRange(0, 50);
		auto randomHeight4 = RGI->getRandomNumberWithRange(0, 50);

		Dregs1->runAction(JumpBy::create(0.5f,Vec2(randomPosX1, randomPosY1), randomHeight1, 1));
		Dregs2->runAction(JumpBy::create(0.5f,Vec2(randomPosX2, randomPosY2), randomHeight2, 1));
		Dregs3->runAction(JumpBy::create(0.5f,Vec2(randomPosX3, randomPosY3), randomHeight3, 1));
		Dregs4->runAction(JumpBy::create(0.5f,Vec2(randomPosX4, randomPosY4), randomHeight4, 1));
	}
		break;
	case ObjectFire:
		break;
	case ObjectPoop:
		break;
	default:
		break;
	}

}

Dregs::~Dregs()
{
}
