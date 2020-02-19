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

	auto randomOverlay = RGI->getRandomNumberWithRange(1, 5);

	switch (randomOverlay)
	{
	case 1:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_1.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398);
		overlay_1_1->setScaleY(0.62937);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 2:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_2.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398);
		overlay_1_1->setScaleY(0.62937);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 3:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_3.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398);
		overlay_1_1->setScaleY(0.62937);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 4:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_4.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398);
		overlay_1_1->setScaleY(0.62937);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 5:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_5.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398);
		overlay_1_1->setScaleY(0.62937);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	default:
		break;
	}

	//��Ƽ ����
	mapLT->getTexture()->setAliasTexParameters();
	mapLB->getTexture()->setAliasTexParameters();
	mapRT->getTexture()->setAliasTexParameters();
	mapRB->getTexture()->setAliasTexParameters();

	mapRect = Rect(position.x - DI->getWinSize().width / 2, position.y - DI->getWinSize().height / 2,DI->getWinSize().width, DI->getWinSize().height);

}

void MapBase::CreateNormalDoorR(Scene * scene, Vec2 position, DoorName doorname)
{
	switch (doorname)
	{
	case NormalDoor:
	{
		doorR = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
		doorR->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR->setRotation(90);
		scene->addChild(doorR, DoorZoder + 1);

		doorR_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
		doorR_1->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR_1->setRotation(90);
		scene->addChild(doorR_1, DoorZoder - 2);

		closeDoorR = Sprite::create("MapImage/Door/door_01_normaldoor_03.png");
		closeDoorR->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y));
		closeDoorR->setAnchorPoint({ 1,0.5 });
		closeDoorR->setRotation(90);
		scene->addChild(closeDoorR, DoorZoder - 1);

		closeDoorR_1 = Sprite::create("MapImage/Door/door_01_normaldoor_04.png");
		closeDoorR_1->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y));
		closeDoorR_1->setRotation(90);
		closeDoorR_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorR_1, DoorZoder - 1);
	}
		break;
	case TreasureDoor:
		break;
	default:
		break;
	}

	closeDoorR->setVisible(false);
	closeDoorR_1->setVisible(false);

	isMakeDoorR = true;
}

void MapBase::CreateNormalDoorL(Scene * scene, Vec2 position, DoorName doorname)
{
	switch (doorname)
	{
	case NormalDoor:
	{
		doorL = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
		doorL->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL->setRotation(-90);
		scene->addChild(doorL, DoorZoder + 1);

		doorL_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
		doorL_1->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL_1->setRotation(-90);
		scene->addChild(doorL_1, DoorZoder - 2);

		closeDoorL = Sprite::create("MapImage/Door/door_01_normaldoor_03.png");
		closeDoorL->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y));
		closeDoorL->setAnchorPoint({ 1,0.5 });
		closeDoorL->setRotation(-90);
		scene->addChild(closeDoorL, DoorZoder - 1);

		closeDoorL_1 = Sprite::create("MapImage/Door/door_01_normaldoor_04.png");
		closeDoorL_1->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y));
		closeDoorL_1->setRotation(-90);
		closeDoorL_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorL_1, DoorZoder - 1);
	}
	break;
	case TreasureDoor:
		break;
	default:
		break;
	}

	closeDoorL->setVisible(false);
	closeDoorL_1->setVisible(false);

	isMakeDoorL = true;
}

void MapBase::CreateNormalDoorT(Scene * scene, Vec2 position, DoorName doorname)
{
	switch (doorname)
	{
	case NormalDoor:
	{
		doorT = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
		doorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		scene->addChild(doorT, DoorZoder + 1);

		doorT_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
		doorT_1->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		scene->addChild(doorT_1, DoorZoder - 2);

		closeDoorT = Sprite::create("MapImage/Door/door_01_normaldoor_03.png");
		closeDoorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD - 5));
		closeDoorT->setAnchorPoint({ 1,0.5 });
		scene->addChild(closeDoorT, DoorZoder - 1);

		closeDoorT_1 = Sprite::create("MapImage/Door/door_01_normaldoor_04.png");
		closeDoorT_1->setPosition(Vec2(position.x, position.y + DoorCorrectionUD - 5));
		closeDoorT_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorT_1, DoorZoder - 1);
	}
	break;
	case TreasureDoor:
		break;
	default:
		break;
	}

	closeDoorT->setVisible(false);
	closeDoorT_1->setVisible(false);

	isMakeDoorT = true;
}

void MapBase::CreateNormalDoorB(Scene * scene, Vec2 position, DoorName doorname)
{
	switch (doorname)
	{
	case NormalDoor:
	{
		doorB = Sprite::create("MapImage/Door/door_01_normaldoor_01.png");
		doorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB->setFlippedY(true);
		scene->addChild(doorB, DoorZoder + 1);

		doorB_1 = Sprite::create("MapImage/Door/door_01_normaldoor_02.png");
		doorB_1->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB_1->setFlippedY(true);
		scene->addChild(doorB_1, DoorZoder - 2);

		closeDoorB = Sprite::create("MapImage/Door/door_01_normaldoor_03.png");
		closeDoorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD + 5));
		closeDoorB->setAnchorPoint({ 1,0.5 });
		closeDoorB->setFlippedY(true);
		scene->addChild(closeDoorB, DoorZoder - 1);

		closeDoorB_1 = Sprite::create("MapImage/Door/door_01_normaldoor_04.png");
		closeDoorB_1->setPosition(Vec2(position.x, position.y - DoorCorrectionUD + 5));
		closeDoorB_1->setAnchorPoint({ 0,0.5 });
		closeDoorB_1->setFlippedY(true);
		scene->addChild(closeDoorB_1, DoorZoder - 1);
	}
	break;
	case TreasureDoor:
		break;
	default:
		break;
	}

	closeDoorB->setVisible(false);
	closeDoorB_1->setVisible(false);

	isMakeDoorB = true;
}

void MapBase::CollisionToDoor()
{
	if (Player->getRoomNumber() == RoomNumber)
	{
		if (isMakeDoorB && RoomClear &&
			doorB->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y &&
			doorB->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorT && RoomClear &&
			doorT->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y &&
			doorT->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorR && RoomClear &&
			doorR->getBoundingBox().getMidY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMidY() + 10 > Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x &&
			doorR->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorL && RoomClear &&
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

		if (isMakeDoorB && RoomClear)
		{
			if (doorB->getBoundingBox().getMidY() > Player->getIsaacBody()->getPosition().y &&
				doorB->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y - 70);
			
				CI->MoveB();
			}
		}

		if (isMakeDoorT && RoomClear)
		{
			if (doorT->getBoundingBox().getMidY() < Player->getIsaacBody()->getPosition().y &&
				doorT->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y + 70);
				
				CI->MoveT();
			}
		}

		if (isMakeDoorR && RoomClear)
		{
			if (doorR->getBoundingBox().getMidX() < Player->getIsaacBody()->getPosition().x &&
				doorR->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x + 100, Player->getIsaacBody()->getPosition().y);
				
				CI->MoveR();
			}
		}

		if (isMakeDoorL && RoomClear)
		{
			if (doorL->getBoundingBox().getMidX() > Player->getIsaacBody()->getPosition().x &&
				doorL->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x - 100, Player->getIsaacBody()->getPosition().y);
				
				CI->MoveL();
			}
		}
	}


}

void MapBase::ClearCheck()
{
	if (RoomClear)
	{
		if (isMakeDoorR)
		{
			closeDoorR->setVisible(false);
			closeDoorR_1->setVisible(false);
		}
		
		if (isMakeDoorL)
		{
			closeDoorL->setVisible(false);
			closeDoorL_1->setVisible(false);
		}

		if (isMakeDoorT)
		{
			closeDoorT->setVisible(false);
			closeDoorT_1->setVisible(false);
		}

		if (isMakeDoorB)
		{
			closeDoorB->setVisible(false);
			closeDoorB_1->setVisible(false);
		}
	}
	else
	{
		if (isMakeDoorR)
		{
			closeDoorR->setVisible(true);
			closeDoorR_1->setVisible(true);
		}

		if (isMakeDoorL)
		{
			closeDoorL->setVisible(true);
			closeDoorL_1->setVisible(true);
		}

		if (isMakeDoorT)
		{
			closeDoorT->setVisible(true);
			closeDoorT_1->setVisible(true);
		}

		if (isMakeDoorB)
		{
			closeDoorB->setVisible(true);
			closeDoorB_1->setVisible(true);
		}
	}
}

void MapBase::SetRoomNumber()
{
	if (mapRect.containsPoint(Player->getIsaacBody()->getPosition()))
	{
		Player->setRoomNumber(RoomNumber);
	}
}
