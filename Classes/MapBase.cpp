#include "MapBase.h"

MapBase::MapBase()
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("MapImage/basement/basement.plist");

	isMakeDoorR = false;
	isMakeDoorL = false;
	isMakeDoorT = false;
	isMakeDoorB = false;
}

MapBase::~MapBase()
{
}

void MapBase::CreateBaseMentRoom(Scene * scene, Vec2 position)
{
	_position = position;

	mapLT = Sprite::createWithSpriteFrameName("01_basement_01.png");
	mapLT->setAnchorPoint({ 1,0 });
	mapLT->setScaleY(0.9f);
	mapLT->setPosition(position);
	scene->addChild(mapLT, BackGroundZoder);

	mapLB = Sprite::createWithSpriteFrameName("01_basement_01.png");
	mapLB->setAnchorPoint({ 1,1 });
	mapLB->setFlippedY(true);
	mapLB->setScaleY(0.9f);
	mapLB->setPosition(position);
	scene->addChild(mapLB, BackGroundZoder);

	mapRT = Sprite::createWithSpriteFrameName("01_basement_01.png");
	mapRT->setAnchorPoint({ 0,0 });
	mapRT->setFlippedX(true);
	mapRT->setScaleY(0.9f);
	mapRT->setPosition(position);
	scene->addChild(mapRT, BackGroundZoder);

	mapRB = Sprite::createWithSpriteFrameName("01_basement_01.png");
	mapRB->setAnchorPoint({ 0,1 });
	mapRB->setFlippedX(true);
	mapRB->setFlippedY(true);
	mapRB->setScaleY(0.9f);
	mapRB->setPosition(position);
	scene->addChild(mapRB, BackGroundZoder);

	shading_1_1 = Sprite::create("MapImage/shading.png");
	shading_1_1->setPosition(position);
	shading_1_1->setScaleX(1.1f);
	scene->addChild(shading_1_1);

	//안티 적용
	mapLT->getTexture()->setAliasTexParameters();
	mapLB->getTexture()->setAliasTexParameters();
	mapRT->getTexture()->setAliasTexParameters();
	mapRB->getTexture()->setAliasTexParameters();

}

void MapBase::CreateNormalDoorR(Scene * scene, Vec2 position)
{
	doorR = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
	doorR->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
	doorR->setRotation(90);
	scene->addChild(doorR, DoorZoder + 1);

	doorR_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
	doorR_1->setPosition(Vec2(position.x + DoorCorrectionRL,position.y));
	doorR_1->setRotation(90);
	scene->addChild(doorR_1, DoorZoder);

	isMakeDoorR = true;
}

void MapBase::CreateNormalDoorL(Scene * scene, Vec2 position)
{
	doorL = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
	doorL->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
	doorL->setRotation(-90);
	scene->addChild(doorL, DoorZoder + 1);

	doorL_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
	doorL_1->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
	doorL_1->setRotation(-90);
	scene->addChild(doorL_1, DoorZoder);

	isMakeDoorL = true;
}

void MapBase::CreateNormalDoorT(Scene * scene, Vec2 position)
{
	doorT = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
	doorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
	scene->addChild(doorT, DoorZoder + 1);

	doorT_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
	doorT_1->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
	scene->addChild(doorT_1, DoorZoder);

	isMakeDoorT = true;
}

void MapBase::CreateNormalDoorB(Scene * scene, Vec2 position)
{
	doorB = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
	doorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
	doorB->setFlippedY(true);
	scene->addChild(doorB, DoorZoder + 1);

	doorB_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
	doorB_1->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
	doorB_1->setFlippedY(true);
	scene->addChild(doorB_1, DoorZoder);

	isMakeDoorB = true;
}

void MapBase::CollisionToDoor()
{
	if (Player->getRoomNumber() == RoomNumber)
	{
		if (isMakeDoorB &&
			doorB->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y &&
			doorB->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorT &&
			doorT->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y &&
			doorT->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorR && 
			doorR->getBoundingBox().getMidY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMidY() + 10 > Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x &&
			doorR->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorL && 
			doorL->getBoundingBox().getMidY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorL->getBoundingBox().getMidY() + 10 > Player->getIsaacBody()->getPosition().y &&
			doorL->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x &&
			doorL->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(1);
		}
			

		int vecsize = Player->objectVec.size();

		if (isMakeDoorB)
		{
			if (doorB->getBoundingBox().getMidY() > Player->getIsaacBody()->getPosition().y &&
				doorB->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y - 70);
				Player->getIsaacPysicBody()->setPositionOffset(Player->getIsaacPysicBody()->getPositionOffset() + Vec2(0, DI->getWinSize().height));
				
				for (int i = 0; i < vecsize; i++)
				{
					Player->objectVec[i]->ObjectPhysics->setPositionOffset(
						Player->objectVec[i]->ObjectPhysics->getPositionOffset() + Vec2(0, DI->getWinSize().height));
				}

				CI->MoveB();
			}
		}

		if (isMakeDoorT)
		{
			if (doorT->getBoundingBox().getMidY() < Player->getIsaacBody()->getPosition().y &&
				doorT->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y + 70);
				Player->getIsaacPysicBody()->setPositionOffset(Player->getIsaacPysicBody()->getPositionOffset() + Vec2(0, -DI->getWinSize().height));

				for (int i = 0; i < vecsize; i++)
				{
					Player->objectVec[i]->ObjectPhysics->setPositionOffset(
						Player->objectVec[i]->ObjectPhysics->getPositionOffset() + Vec2(0, -DI->getWinSize().height));
				}

				CI->MoveT();
			}
		}

		if (isMakeDoorR)
		{
			if (doorR->getBoundingBox().getMidX() < Player->getIsaacBody()->getPosition().x &&
				doorR->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x + 100, Player->getIsaacBody()->getPosition().y);
				Player->getIsaacPysicBody()->setPositionOffset(Player->getIsaacPysicBody()->getPositionOffset() + Vec2(-DI->getWinSize().width, 0));

				for (int i = 0; i < vecsize; i++)
				{

					Player->objectVec[i]->ObjectPhysics->setPositionOffset(
						Player->objectVec[i]->ObjectPhysics->getPositionOffset() + Vec2(-DI->getWinSize().width, 0));
				}

				CI->MoveR();
			}
		}

		if (isMakeDoorL)
		{
			if (doorL->getBoundingBox().getMidX() > Player->getIsaacBody()->getPosition().x &&
				doorL->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x - 100, Player->getIsaacBody()->getPosition().y);
				Player->getIsaacPysicBody()->setPositionOffset(Player->getIsaacPysicBody()->getPositionOffset() + Vec2(DI->getWinSize().width, 0));

				for (int i = 0; i < vecsize; i++)
				{

					Player->objectVec[i]->ObjectPhysics->setPositionOffset(
						Player->objectVec[i]->ObjectPhysics->getPositionOffset() + Vec2(DI->getWinSize().width, 0));
				}

				CI->MoveL();
			}
		}
	}


}