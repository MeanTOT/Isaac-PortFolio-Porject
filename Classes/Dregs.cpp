#include "Dregs.h"

Dregs::Dregs(Scene * scene, Vec2 position, ObjectName objectname, int zoder)
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Object/Dregs/PoopDregs1.plist");
	cache->addSpriteFramesWithFile("Object/Dregs/BloodGibs.plist");
	cache->addSpriteFramesWithFile("Object/Dregs/Effect_Toothgibs.plist");

	for (int i = 0; i < 30; i++)
	{
		dregsPhysics[i] = nullptr;
	}

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

			scene->addChild(dregs[i], zoder - 5000);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 50);

			dregs[i]->runAction(Sequence::create(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1), 
				CallFunc::create(CC_CALLBACK_0(Dregs::RemovePhysicsBody,this)),nullptr));
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
			scene->addChild(dregs[i], zoder - 5000);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 50);

			dregs[i]->runAction(Sequence::create(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1),
				CallFunc::create(CC_CALLBACK_0(Dregs::RemovePhysicsBody, this)), nullptr));
		}
	}		 
		break;
	case ObjectMonster:
	{
		dregs[0] = Sprite::createWithSpriteFrameName("bloodgibs_01.png");
		dregs[1] = Sprite::createWithSpriteFrameName("bloodgibs_02.png");
		dregs[2] = Sprite::createWithSpriteFrameName("bloodgibs_03.png");
		dregs[3] = Sprite::createWithSpriteFrameName("bloodgibs_04.png");
		dregs[4] = Sprite::createWithSpriteFrameName("bloodgibs_05.png");
		dregs[5] = Sprite::createWithSpriteFrameName("bloodgibs_06.png");
		dregs[6] = Sprite::createWithSpriteFrameName("bloodgibs_07.png");
		dregs[7] = Sprite::createWithSpriteFrameName("bloodgibs_08.png");
		dregs[8] = Sprite::createWithSpriteFrameName("bloodgibs_09.png");
		dregs[9] = Sprite::createWithSpriteFrameName("bloodgibs_10.png");
		dregs[10] = Sprite::createWithSpriteFrameName("bloodgibs_11.png");
		dregs[11] = Sprite::createWithSpriteFrameName("bloodgibs_12.png");
		dregs[12] = Sprite::createWithSpriteFrameName("bloodgibs_13.png");
		dregs[13] = Sprite::createWithSpriteFrameName("bloodgibs_14.png");
		dregs[14] = Sprite::createWithSpriteFrameName("bloodgibs_15.png");
		dregs[15] = Sprite::createWithSpriteFrameName("bloodgibs_16.png");
		dregs[16] = Sprite::createWithSpriteFrameName("bloodgibs_17.png");
		dregs[17] = Sprite::createWithSpriteFrameName("bloodgibs_18.png");
		dregs[18] = Sprite::createWithSpriteFrameName("bloodgibs_19.png");
		dregs[19] = Sprite::createWithSpriteFrameName("bloodgibs_20.png");
		dregs[20] = Sprite::createWithSpriteFrameName("bloodgibs_21.png");
		dregs[21] = Sprite::createWithSpriteFrameName("bloodgibs_22.png");
		dregs[22] = Sprite::createWithSpriteFrameName("bloodgibs_23.png");
		dregs[23] = Sprite::createWithSpriteFrameName("bloodgibs_24.png");
		dregs[24] = Sprite::createWithSpriteFrameName("bloodgibs_25.png");
		dregs[25] = Sprite::createWithSpriteFrameName("bloodgibs_26.png");
		

		for (int i = 0; i < 26; i++)
		{
			randomAddChild[i] = RGI->getPercentage(0.2f);

			if (!randomAddChild[i])
				continue;

			dregs[i]->setPosition(position.x, position.y);
			scene->addChild(dregs[i], zoder - 5000);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 100);

			dregs[i]->runAction(Sequence::create(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1),
				CallFunc::create(CC_CALLBACK_0(Dregs::RemovePhysicsBody, this)), nullptr));
		}
	}
		break;
	case ObjectRock_Cave:
	{
		dregs[0] = Sprite::create("Object/Rock_Cave/rocks_caves_dregs_01.png");
		dregs[1] = Sprite::create("Object/Rock_Cave/rocks_caves_dregs_02.png");
		dregs[2] = Sprite::create("Object/Rock_Cave/rocks_caves_dregs_03.png");
		dregs[3] = Sprite::create("Object/Rock_Cave/rocks_caves_dregs_04.png");

		for (int i = 0; i < 4; i++)
		{
			dregs[i]->setPosition(position.x, position.y);
			scene->addChild(dregs[i], zoder - 5000);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 50);

			dregs[i]->runAction(Sequence::create(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1),
				CallFunc::create(CC_CALLBACK_0(Dregs::RemovePhysicsBody, this)), nullptr));
		}
	}
		break;
	case ObjectMushRoom_Cave:
	{
		dregs[0] = Sprite::create("Object/Rock_Cave/mushroom_caves_dregs_01.png");
		dregs[1] = Sprite::create("Object/Rock_Cave/mushroom_caves_dregs_02.png");
		dregs[2] = Sprite::create("Object/Rock_Cave/mushroom_caves_dregs_03.png");
		dregs[3] = Sprite::create("Object/Rock_Cave/mushroom_caves_dregs_04.png");

		for (int i = 0; i < 4; i++)
		{
			dregs[i]->setPosition(position.x, position.y);
			scene->addChild(dregs[i], zoder - 5000);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 50);

			dregs[i]->runAction(Sequence::create(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1),
				CallFunc::create(CC_CALLBACK_0(Dregs::RemovePhysicsBody, this)), nullptr));
		}
	}
		break;
	case ObjectBone:
	{
		dregs[0] = Sprite::createWithSpriteFrameName("effect_toothgibs_01.png");
		dregs[1] = Sprite::createWithSpriteFrameName("effect_toothgibs_02.png");
		dregs[2] = Sprite::createWithSpriteFrameName("effect_toothgibs_03.png");
		dregs[3] = Sprite::createWithSpriteFrameName("effect_toothgibs_04.png");
		dregs[4] = Sprite::createWithSpriteFrameName("effect_toothgibs_05.png");
		dregs[5] = Sprite::createWithSpriteFrameName("effect_toothgibs_06.png");
		dregs[6] = Sprite::createWithSpriteFrameName("effect_toothgibs_07.png");
		dregs[7] = Sprite::createWithSpriteFrameName("effect_toothgibs_08.png");

		for (int i = 0; i < 8; i++)
		{
			dregs[i]->setPosition(position.x, position.y);

			scene->addChild(dregs[i], zoder - 5000);
			randomPosX[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomPosY[i] = RGI->getRandomNumberWithRange(-25, 25);
			randomHeight[i] = RGI->getRandomNumberWithRange(0, 50);

			dregs[i]->runAction(Sequence::create(JumpBy::create(0.5f, Vec2(randomPosX[i], randomPosY[i]), randomHeight[i], 1), RemoveSelf::create(), nullptr));
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

void Dregs::RemovePhysicsBody()
{
	for (int i = 0; i < 30; i++)
	{
		if (dregsPhysics[i] != nullptr)
			dregsPhysics[i]->removeFromWorld();
	}
}
