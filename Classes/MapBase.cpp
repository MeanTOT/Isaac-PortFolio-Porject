#include "MapBase.h"

MapBase::MapBase()
{
	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("MapImage/basement/basement.plist");
	cache->addSpriteFramesWithFile("MapImage/Caves/Caves.plist");
	cache->addSpriteFramesWithFile("MapImage/Shop/MapImage_Shop.plist");

	isMakeDoorR = false;
	isMakeDoorL = false;
	isMakeDoorT = false;
	isMakeDoorB = false;
	clearOnDidFinishCount = 50;
	
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
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 2:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_2.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 3:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_3.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 4:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_4.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	case 5:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_5.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
		break;
	default:
		break;
	}

	//안티 적용
	mapLT->getTexture()->setAliasTexParameters();
	mapLB->getTexture()->setAliasTexParameters();
	mapRT->getTexture()->setAliasTexParameters();
	mapRB->getTexture()->setAliasTexParameters();

	mapRect = Rect(position.x - DI->getWinSize().width / 2, position.y - DI->getWinSize().height / 2,DI->getWinSize().width, DI->getWinSize().height);

}

void MapBase::CreateBaseMentBossRoom(Scene * scene, Vec2 position)
{
	_position = position;

	mapLT = Sprite::createWithSpriteFrameName("01_basement_04.png");
	mapLT->setAnchorPoint({ 1,0 });
	mapLT->setScaleY(0.9f);
	mapLT->setPosition(position);
	scene->addChild(mapLT, BackGroundZoder);

	mapLB = Sprite::createWithSpriteFrameName("01_basement_04.png");
	mapLB->setAnchorPoint({ 1,1 });
	mapLB->setFlippedY(true);
	mapLB->setScaleY(0.9f);
	mapLB->setPosition(position);
	scene->addChild(mapLB, BackGroundZoder);

	mapRT = Sprite::createWithSpriteFrameName("01_basement_04.png");
	mapRT->setAnchorPoint({ 0,0 });
	mapRT->setFlippedX(true);
	mapRT->setScaleY(0.9f);
	mapRT->setPosition(position);
	scene->addChild(mapRT, BackGroundZoder);

	mapRB = Sprite::createWithSpriteFrameName("01_basement_04.png");
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
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 2:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_2.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 3:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_3.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 4:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_4.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 5:
	{
		overlay_1_1 = Sprite::create("MapImage/basement/1x1_overlay_5.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	default:
		break;
	}

	//안티 적용
	mapLT->getTexture()->setAliasTexParameters();
	mapLB->getTexture()->setAliasTexParameters();
	mapRT->getTexture()->setAliasTexParameters();
	mapRB->getTexture()->setAliasTexParameters();

	mapRect = Rect(position.x - DI->getWinSize().width / 2, position.y - DI->getWinSize().height / 2, DI->getWinSize().width, DI->getWinSize().height);
}

void MapBase::CreateCavesRoom(Scene * scene, Vec2 position)
{
	_position = position;

	mapLT = Sprite::createWithSpriteFrameName("caves_04.png");
	mapLT->setAnchorPoint({ 1,0 });
	mapLT->setScaleY(0.9f);
	mapLT->setPosition(position);
	scene->addChild(mapLT, BackGroundZoder);

	mapLB = Sprite::createWithSpriteFrameName("caves_04.png");
	mapLB->setAnchorPoint({ 1,1 });
	mapLB->setFlippedY(true);
	mapLB->setScaleY(0.9f);
	mapLB->setPosition(position);
	scene->addChild(mapLB, BackGroundZoder);

	mapRT = Sprite::createWithSpriteFrameName("caves_04.png");
	mapRT->setAnchorPoint({ 0,0 });
	mapRT->setFlippedX(true);
	mapRT->setScaleY(0.9f);
	mapRT->setPosition(position);
	scene->addChild(mapRT, BackGroundZoder);

	mapRB = Sprite::createWithSpriteFrameName("caves_04.png");
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
		overlay_1_1 = Sprite::create("MapImage/Caves/1x1_overlay_1.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 2:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x1_overlay_2.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 3:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x1_overlay_3.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 4:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x1_overlay_4.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 5:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x1_overlay_5.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 6:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x2_overlay_1.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 7:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x2_overlay_2.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 8:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x2_overlay_3.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 9:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x2_overlay_4.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 10:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/1x2_overlay_5.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 11:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x1_overlay_1.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 12:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x1_overlay_2.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 13:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x1_overlay_3.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	case 14:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x1_overlay_4.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	case 15:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x1_overlay_5.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 16:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x2_overlay_1.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 17:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x2_overlay_2.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 18:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x2_overlay_3.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 19:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x2_overlay_4.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	case 20:
	{
		overlay_1_1 = Sprite::create("MapImage/Caves/2x2_overlay_5.png");
		overlay_1_1->setPosition(position);
		overlay_1_1->setScaleX(0.72398f);
		overlay_1_1->setScaleY(0.62937f);
		scene->addChild(overlay_1_1, StageOverlayZoder);
	}
	break;
	default:
		break;
	}

	//안티 적용
	mapLT->getTexture()->setAliasTexParameters();
	mapLB->getTexture()->setAliasTexParameters();
	mapRT->getTexture()->setAliasTexParameters();
	mapRB->getTexture()->setAliasTexParameters();

	mapRect = Rect(position.x - DI->getWinSize().width / 2, position.y - DI->getWinSize().height / 2, DI->getWinSize().width, DI->getWinSize().height);
}

void MapBase::CreateShopRoom(Scene * scene, Vec2 position)
{
	_position = position;

	mapLT = Sprite::createWithSpriteFrameName("shop_01.png");
	mapLT->setAnchorPoint({ 1,0 });
	mapLT->setScaleY(0.9f);
	mapLT->setPosition(position);
	scene->addChild(mapLT, BackGroundZoder);

	mapLB = Sprite::createWithSpriteFrameName("shop_01.png");
	mapLB->setAnchorPoint({ 1,1 });
	mapLB->setFlippedY(true);
	mapLB->setScaleY(0.9f);
	mapLB->setPosition(position);
	scene->addChild(mapLB, BackGroundZoder);

	mapRT = Sprite::createWithSpriteFrameName("shop_01.png");
	mapRT->setAnchorPoint({ 0,0 });
	mapRT->setFlippedX(true);
	mapRT->setScaleY(0.9f);
	mapRT->setPosition(position);
	scene->addChild(mapRT, BackGroundZoder);

	mapRB = Sprite::createWithSpriteFrameName("shop_01.png");
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

	mapRect = Rect(position.x - DI->getWinSize().width / 2, position.y - DI->getWinSize().height / 2, DI->getWinSize().width, DI->getWinSize().height);
}

void MapBase::CreateDoorR(Scene * scene, Vec2 position, DoorName doorname)
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

		doorR->setTag(OpenDoor);
	}
		break;
	case TreasureDoor:
	{
		doorR = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorR->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR->setRotation(90);
		scene->addChild(doorR, DoorZoder + 1);

		doorR_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorR_1->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR_1->setRotation(90);
		scene->addChild(doorR_1, DoorZoder - 2);

		closeDoorR = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorR->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y));
		closeDoorR->setAnchorPoint({ 1,0.5 });
		closeDoorR->setRotation(90);
		scene->addChild(closeDoorR, DoorZoder - 1);

		closeDoorR_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorR_1->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y + 5));
		closeDoorR_1->setRotation(90);
		closeDoorR_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorR_1, DoorZoder - 1);

		doorR->setTag(CloseDoor);
	}
		break;
	case TreasureNoneKeyDoor:
	{
		doorR = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorR->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR->setRotation(90);
		scene->addChild(doorR, DoorZoder + 1);

		doorR_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorR_1->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR_1->setRotation(90);
		scene->addChild(doorR_1, DoorZoder - 2);

		closeDoorR = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorR->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y));
		closeDoorR->setAnchorPoint({ 1,0.5 });
		closeDoorR->setRotation(90);
		scene->addChild(closeDoorR, DoorZoder - 1);

		closeDoorR_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorR_1->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y + 5));
		closeDoorR_1->setRotation(90);
		closeDoorR_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorR_1, DoorZoder - 1);

		doorR->setTag(OpenDoor);
	}
	break;
	case BossRoomDoor:
	{
		doorR = Sprite::create("MapImage/Door/door_bossroomdoor_01.png");
		doorR->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR->setRotation(90);
		scene->addChild(doorR, DoorZoder + 1);

		doorR_1 = Sprite::create("MapImage/Door/door_bossroomdoor_02.png");
		doorR_1->setPosition(Vec2(position.x + DoorCorrectionRL, position.y));
		doorR_1->setRotation(90);
		doorR_1->setScaleX(1.4f);
		scene->addChild(doorR_1, DoorZoder - 2);

		closeDoorR = Sprite::create("MapImage/Door/door_bossroomdoor_03.png");
		closeDoorR->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y - 5));
		closeDoorR->setAnchorPoint({ 1,0.5 });
		closeDoorR->setRotation(90);
		closeDoorR->setScaleX(1.4f);
		scene->addChild(closeDoorR, DoorZoder - 1);

		closeDoorR_1 = Sprite::create("MapImage/Door/door_bossroomdoor_04.png");
		closeDoorR_1->setPosition(Vec2(position.x + DoorCorrectionRL - 5, position.y));
		closeDoorR_1->setRotation(90);
		closeDoorR_1->setAnchorPoint({ 0,0.5 });
		closeDoorR_1->setScaleX(1.4f);
		scene->addChild(closeDoorR_1, DoorZoder - 1);

		BossDoorLightR = Sprite::create("MapImage/Door/door_bossroomdoor_07.png");
		BossDoorLightR->setPosition(Vec2(position.x + DoorCorrectionRL - 33, position.y));
		BossDoorLightR->setRotation(90);
		BossDoorLightR->setVisible(false);
		scene->addChild(BossDoorLightR, DoorZoder - 1);

		doorR->setTag(OpenDoor);
	}
		break;
	default:
		break;
	}

	closeDoorR->setVisible(true);
	closeDoorR_1->setVisible(true);

	_doorname = doorname;

	isMakeDoorR = true;
}

void MapBase::CreateDoorL(Scene * scene, Vec2 position, DoorName doorname)
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

		doorL->setTag(OpenDoor);
	}
	break;
	case TreasureDoor:
	{
		doorL = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorL->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL->setRotation(-90);
		scene->addChild(doorL, DoorZoder + 1);

		doorL_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorL_1->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL_1->setRotation(-90);
		scene->addChild(doorL_1, DoorZoder - 2);

		closeDoorL = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorL->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y));
		closeDoorL->setAnchorPoint({ 1,0.5 });
		closeDoorL->setRotation(-90);
		scene->addChild(closeDoorL, DoorZoder - 1);

		closeDoorL_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorL_1->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y - 5));
		closeDoorL_1->setRotation(-90);
		closeDoorL_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorL_1, DoorZoder - 1);

		doorL->setTag(CloseDoor);
	}
		break;
	case TreasureNoneKeyDoor:
	{
		doorL = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorL->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL->setRotation(-90);
		scene->addChild(doorL, DoorZoder + 1);

		doorL_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorL_1->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL_1->setRotation(-90);
		scene->addChild(doorL_1, DoorZoder - 2);

		closeDoorL = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorL->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y));
		closeDoorL->setAnchorPoint({ 1,0.5 });
		closeDoorL->setRotation(-90);
		scene->addChild(closeDoorL, DoorZoder - 1);

		closeDoorL_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorL_1->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y - 5));
		closeDoorL_1->setRotation(-90);
		closeDoorL_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorL_1, DoorZoder - 1);

		doorL->setTag(OpenDoor);
	}
	break;
	case BossRoomDoor:
	{
		doorL = Sprite::create("MapImage/Door/door_bossroomdoor_01.png");
		doorL->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL->setRotation(-90);
		scene->addChild(doorL, DoorZoder + 1);

		doorL_1 = Sprite::create("MapImage/Door/door_bossroomdoor_02.png");
		doorL_1->setPosition(Vec2(position.x - DoorCorrectionRL, position.y));
		doorL_1->setScaleX(1.4f);
		doorL_1->setRotation(-90);

		scene->addChild(doorL_1, DoorZoder - 2);

		closeDoorL = Sprite::create("MapImage/Door/door_bossroomdoor_03.png");
		closeDoorL->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y + 5));
		closeDoorL->setAnchorPoint({ 1,0.5 });
		closeDoorL->setScaleX(1.4f);
		closeDoorL->setRotation(-90);
		scene->addChild(closeDoorL, DoorZoder - 1);

		closeDoorL_1 = Sprite::create("MapImage/Door/door_bossroomdoor_04.png");
		closeDoorL_1->setPosition(Vec2(position.x - DoorCorrectionRL + 5, position.y));
		closeDoorL_1->setRotation(-90);
		closeDoorL_1->setScaleX(1.4f);
		closeDoorL_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorL_1, DoorZoder - 1);

		BossDoorLightL = Sprite::create("MapImage/Door/door_bossroomdoor_07.png");
		BossDoorLightL->setPosition(Vec2(position.x - DoorCorrectionRL + 33, position.y));
		BossDoorLightL->setRotation(-90);
		BossDoorLightL->setVisible(false);
		scene->addChild(BossDoorLightL, DoorZoder - 1);

		doorL->setTag(OpenDoor);
	}
	break;
	default:
		break;
	}

	_doorname = doorname;

	closeDoorL->setVisible(true);
	closeDoorL_1->setVisible(true);

	isMakeDoorL = true;
}

void MapBase::CreateDoorT(Scene * scene, Vec2 position, DoorName doorname)
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

		doorT->setTag(OpenDoor);
	}
	break;
	case TreasureDoor:
	{
		doorT = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		scene->addChild(doorT, DoorZoder + 1);

		doorT_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorT_1->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		scene->addChild(doorT_1, DoorZoder - 2);

		closeDoorT = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD - 5));
		closeDoorT->setAnchorPoint({ 1,0.5 });
		scene->addChild(closeDoorT, DoorZoder - 1);

		closeDoorT_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorT_1->setPosition(Vec2(position.x - 5, position.y + DoorCorrectionUD - 5));
		closeDoorT_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorT_1, DoorZoder - 1);

		doorT->setTag(CloseDoor);
	}
		break;
	case TreasureNoneKeyDoor:
	{
		doorT = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		scene->addChild(doorT, DoorZoder + 1);

		doorT_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorT_1->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		scene->addChild(doorT_1, DoorZoder - 2);

		closeDoorT = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD - 5));
		closeDoorT->setAnchorPoint({ 1,0.5 });
		scene->addChild(closeDoorT, DoorZoder - 1);

		closeDoorT_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorT_1->setPosition(Vec2(position.x - 5, position.y + DoorCorrectionUD - 5));
		closeDoorT_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorT_1, DoorZoder - 1);

		doorT->setTag(OpenDoor);
	}
	break;
	case BossRoomDoor:
	{
		doorT = Sprite::create("MapImage/Door/door_bossroomdoor_01.png");
		doorT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		scene->addChild(doorT, DoorZoder + 1);

		doorT_1 = Sprite::create("MapImage/Door/door_bossroomdoor_02.png");
		doorT_1->setPosition(Vec2(position.x, position.y + DoorCorrectionUD));
		doorT_1->setScaleX(1.4f);
		scene->addChild(doorT_1, DoorZoder - 2);

		closeDoorT = Sprite::create("MapImage/Door/door_bossroomdoor_03.png");
		closeDoorT->setPosition(Vec2(position.x + 5, position.y + DoorCorrectionUD - 5));
		closeDoorT->setScaleX(1.4f);
		closeDoorT->setAnchorPoint({ 1,0.5 });
		scene->addChild(closeDoorT, DoorZoder - 1);

		closeDoorT_1 = Sprite::create("MapImage/Door/door_bossroomdoor_04.png");
		closeDoorT_1->setPosition(Vec2(position.x, position.y + DoorCorrectionUD - 5));
		closeDoorT_1->setScaleX(1.4f);
		closeDoorT_1->setAnchorPoint({ 0,0.5 });
		scene->addChild(closeDoorT_1, DoorZoder - 1);

		BossDoorLightT = Sprite::create("MapImage/Door/door_bossroomdoor_07.png");
		BossDoorLightT->setPosition(Vec2(position.x, position.y + DoorCorrectionUD - 33));
		BossDoorLightT->setVisible(false);
		scene->addChild(BossDoorLightT, DoorZoder - 1);

		doorT->setTag(OpenDoor);
	}
	break;
	default:
		break;
	}

	_doorname = doorname;

	closeDoorT->setVisible(true);
	closeDoorT_1->setVisible(true);

	isMakeDoorT = true;
}

void MapBase::CreateDoorB(Scene * scene, Vec2 position, DoorName doorname)
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

		doorB->setTag(OpenDoor);
	}
	break;
	case TreasureDoor:
	{
		doorB = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB->setFlippedY(true);
		scene->addChild(doorB, DoorZoder + 1);

		doorB_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorB_1->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB_1->setFlippedY(true);
		scene->addChild(doorB_1, DoorZoder - 2);

		closeDoorB = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD + 5));
		closeDoorB->setAnchorPoint({ 1,0.5 });
		closeDoorB->setFlippedY(true);
		scene->addChild(closeDoorB, DoorZoder - 1);

		closeDoorB_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorB_1->setPosition(Vec2(position.x - 5, position.y - DoorCorrectionUD + 5));
		closeDoorB_1->setAnchorPoint({ 0,0.5 });
		closeDoorB_1->setFlippedY(true);
		scene->addChild(closeDoorB_1, DoorZoder - 1);

		doorB->setTag(CloseDoor);
	}
		break;
	case TreasureNoneKeyDoor:
	{
		doorB = Sprite::create("MapImage/Door/door_treasureroomdoor_01.png");
		doorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB->setFlippedY(true);
		scene->addChild(doorB, DoorZoder + 1);

		doorB_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_02.png");
		doorB_1->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB_1->setFlippedY(true);
		scene->addChild(doorB_1, DoorZoder - 2);

		closeDoorB = Sprite::create("MapImage/Door/door_treasureroomdoor_03.png");
		closeDoorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD + 5));
		closeDoorB->setAnchorPoint({ 1,0.5 });
		closeDoorB->setFlippedY(true);
		scene->addChild(closeDoorB, DoorZoder - 1);

		closeDoorB_1 = Sprite::create("MapImage/Door/door_treasureroomdoor_06.png");
		closeDoorB_1->setPosition(Vec2(position.x - 5, position.y - DoorCorrectionUD + 5));
		closeDoorB_1->setAnchorPoint({ 0,0.5 });
		closeDoorB_1->setFlippedY(true);
		scene->addChild(closeDoorB_1, DoorZoder - 1);

		doorB->setTag(OpenDoor);
	}
	break;
	case BossRoomDoor:
	{
		doorB = Sprite::create("MapImage/Door/door_bossroomdoor_01.png");
		doorB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB->setFlippedY(true);
		scene->addChild(doorB, DoorZoder + 1);

		doorB_1 = Sprite::create("MapImage/Door/door_bossroomdoor_02.png");
		doorB_1->setPosition(Vec2(position.x, position.y - DoorCorrectionUD));
		doorB_1->setFlippedY(true);
		doorB_1->setScaleX(1.4f);
		scene->addChild(doorB_1, DoorZoder - 2);

		closeDoorB = Sprite::create("MapImage/Door/door_bossroomdoor_03.png");
		closeDoorB->setPosition(Vec2(position.x + 5, position.y - DoorCorrectionUD + 5));
		closeDoorB->setAnchorPoint({ 1,0.5 });
		closeDoorB->setFlippedY(true);
		closeDoorB->setScaleX(1.4f);
		scene->addChild(closeDoorB, DoorZoder - 1);

		closeDoorB_1 = Sprite::create("MapImage/Door/door_bossroomdoor_04.png");
		closeDoorB_1->setPosition(Vec2(position.x, position.y - DoorCorrectionUD + 5));
		closeDoorB_1->setAnchorPoint({ 0,0.5 });
		closeDoorB_1->setFlippedY(true);
		closeDoorB_1->setScaleX(1.4f);
		scene->addChild(closeDoorB_1, DoorZoder - 1);

		BossDoorLightB = Sprite::create("MapImage/Door/door_bossroomdoor_07.png");
		BossDoorLightB->setPosition(Vec2(position.x, position.y - DoorCorrectionUD + 33));
		BossDoorLightB->setVisible(false);
		BossDoorLightB->setFlippedY(true);
		scene->addChild(BossDoorLightB, DoorZoder - 1);

		doorB->setTag(OpenDoor);
	}
	break;
	default:
		break;
	}

	_doorname = doorname;

	closeDoorB->setVisible(true);
	closeDoorB_1->setVisible(true);

	isMakeDoorB = true;
}

void MapBase::CollisionToDoor()
{
	// ------------------------------------- [ 문이 열려있을때 피직스 충돌 정지 ] ------------------------------------- //

	if (Player->getRoomNumber() == RoomNumber)
	{
		if (isMakeDoorB && RoomClear &&
			doorB->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y &&
			doorB->getBoundingBox().getMaxY() + 10 > Player->getIsaacBody()->getPosition().y && doorB->getTag() == OpenDoor)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorT && RoomClear &&
			doorT->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMinY() - 10< Player->getIsaacBody()->getPosition().y &&
			doorT->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y && doorT->getTag() == OpenDoor)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorR && RoomClear &&
			doorR->getBoundingBox().getMidY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMidY() + 10 > Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMinX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorR->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x && doorR->getTag() == OpenDoor)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else if (isMakeDoorL && RoomClear &&
			doorL->getBoundingBox().getMidY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorL->getBoundingBox().getMidY() + 10 > Player->getIsaacBody()->getPosition().y &&
			doorL->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x &&
			doorL->getBoundingBox().getMaxX() + 10 > Player->getIsaacBody()->getPosition().x && doorL->getTag() == OpenDoor)
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(0);
		}
		else
		{
			Player->getIsaacPysicBody()->setCollisionBitmask(1);
		}

		// ------------------------------------- [ 문 통과시 카메라 액션 ] ------------------------------------- //

		int vecsize = Player->objectVec.size();
		if (isMakeDoorB && RoomClear)
		{
			if (doorB->getBoundingBox().getMidY() > Player->getIsaacBody()->getPosition().y &&
				doorB->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y - 70);
			
				CI->MoveB();
				
				Player->setMiniMapPlayerD(true);
			}
		}

		if (isMakeDoorT && RoomClear)
		{
			if (doorT->getBoundingBox().getMidY() < Player->getIsaacBody()->getPosition().y &&
				doorT->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y + 70);
				
				CI->MoveT();

				Player->setMiniMapPlayerU(true);
			}
		}

		if (isMakeDoorR && RoomClear)
		{
			if (doorR->getBoundingBox().getMidX() < Player->getIsaacBody()->getPosition().x &&
				doorR->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x + 100, Player->getIsaacBody()->getPosition().y);
				
				CI->MoveR();

				Player->setMiniMapPlayerR(true);
			}
		}

		if (isMakeDoorL && RoomClear)
		{
			if (doorL->getBoundingBox().getMidX() > Player->getIsaacBody()->getPosition().x &&
				doorL->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x)
			{
				Player->getIsaacBody()->setPosition(Player->getIsaacBody()->getPosition().x - 100, Player->getIsaacBody()->getPosition().y);
				
				CI->MoveL();

				Player->setMiniMapPlayerL(true);
			}
		}

		// ------------------------------------- [ 잠겨있는 문을 열쇠로 열때 ] ------------------------------------- //

		if (isMakeDoorB && RoomClear &&
			doorB->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorB->getBoundingBox().getMinY() < Player->getIsaacBody()->getPosition().y &&
			doorB->getBoundingBox().getMaxY() + 10 > Player->getIsaacBody()->getPosition().y && doorB->getTag() == CloseDoor)
		{
			if (_doorname == TreasureDoor)
			{
				if (Player->getKeyCount() > 0)
				{
					Player->getDoorOpenKey()->setVisible(true);
					Player->getDoorOpenKey()->setPosition(doorB->getPosition().x, doorB->getPosition().y + 10);
					Player->getDoorOpenKey()->setRotation(180);
					if (!Player->getDoorOpenKey()->getNumberOfRunningActions())
					{
						Player->getDoorOpenKey()->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(MapBase::PlayUnlockSound, this)), Player->getDoorOpenkeyAnimate(),
							CallFunc::create(CC_CALLBACK_0(MapBase::ChangeDoorBTag, this)), nullptr));
					}
					
				}
			}
		}
		if (isMakeDoorT && RoomClear &&
			doorT->getBoundingBox().getMidX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMidX() + 10 > Player->getIsaacBody()->getPosition().x &&
			doorT->getBoundingBox().getMinY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorT->getBoundingBox().getMaxY() > Player->getIsaacBody()->getPosition().y && doorT->getTag() == CloseDoor)
		{
			if (_doorname == TreasureDoor)
			{
				if (Player->getKeyCount() > 0)
				{
					Player->getDoorOpenKey()->setVisible(true);
					Player->getDoorOpenKey()->setPosition(doorT->getPosition().x, doorT->getPosition().y - 10);

					if (!Player->getDoorOpenKey()->getNumberOfRunningActions())
					{
						Player->getDoorOpenKey()->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(MapBase::PlayUnlockSound, this)), Player->getDoorOpenkeyAnimate(),
							CallFunc::create(CC_CALLBACK_0(MapBase::ChangeDoorTTag, this)), nullptr));
					}			
				}
			}
		}
		if (isMakeDoorR && RoomClear &&
			doorR->getBoundingBox().getMidY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMidY() + 10 > Player->getIsaacBody()->getPosition().y &&
			doorR->getBoundingBox().getMinX() - 10 < Player->getIsaacBody()->getPosition().x &&
			doorR->getBoundingBox().getMaxX() > Player->getIsaacBody()->getPosition().x && doorR->getTag() == CloseDoor)
		{
			if (_doorname == TreasureDoor)
			{
				if (Player->getKeyCount() > 0)
				{
					Player->getDoorOpenKey()->setVisible(true);
					Player->getDoorOpenKey()->setPosition(doorR->getPosition().x - 10, doorR->getPosition().y);
					Player->getDoorOpenKey()->setRotation(90);

					if (!Player->getDoorOpenKey()->getNumberOfRunningActions())
					{
						Player->getDoorOpenKey()->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(MapBase::PlayUnlockSound, this)), Player->getDoorOpenkeyAnimate(),
							CallFunc::create(CC_CALLBACK_0(MapBase::ChangeDoorRTag, this)), nullptr));
					}
				}

			}
		}
		if (isMakeDoorL && RoomClear &&
			doorL->getBoundingBox().getMidY() - 10 < Player->getIsaacBody()->getPosition().y &&
			doorL->getBoundingBox().getMidY() + 10 > Player->getIsaacBody()->getPosition().y &&
			doorL->getBoundingBox().getMinX() < Player->getIsaacBody()->getPosition().x &&
			doorL->getBoundingBox().getMaxX() + 10 > Player->getIsaacBody()->getPosition().x && doorL->getTag() == CloseDoor)
		{
			if (_doorname == TreasureDoor)
			{
				if (Player->getKeyCount() > 0)
				{
					Player->getDoorOpenKey()->setVisible(true);
					Player->getDoorOpenKey()->setPosition(doorL->getPosition().x + 10, doorL->getPosition().y);
					Player->getDoorOpenKey()->setRotation(-90);

					if (!Player->getDoorOpenKey()->getNumberOfRunningActions())
					{
						Player->getDoorOpenKey()->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(MapBase::PlayUnlockSound, this)), Player->getDoorOpenkeyAnimate(),
							CallFunc::create(CC_CALLBACK_0(MapBase::ChangeDoorLTag, this)), nullptr));
					}
				}
			}
		}	
	}
}

void MapBase::ClearCheck()
{
	if (Player->getRoomNumber() == RoomNumber)
	{
		if (Player->monsterVec.size() == 0)
		{
			if (!RoomClear)
			{
				RoomClear = true;
				SMI->PlayDoorHeavyOpen();
			}
		}
		else
			RoomClear = false;

	}

	if (RoomClear)
	{
		if (isMakeDoorR && doorR->getTag() == OpenDoor)
		{
			closeDoorR->setVisible(false);
			closeDoorR_1->setVisible(false);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightR->setVisible(true);
			}
		}
		
		if (isMakeDoorL && doorL->getTag() == OpenDoor)
		{
			closeDoorL->setVisible(false);
			closeDoorL_1->setVisible(false);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightL->setVisible(true);
			}
		}

		if (isMakeDoorT && doorT->getTag() == OpenDoor)
		{
			closeDoorT->setVisible(false);
			closeDoorT_1->setVisible(false);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightT->setVisible(true);
			}
		}

		if (isMakeDoorB && doorB->getTag() == OpenDoor)
		{
			closeDoorB->setVisible(false);
			closeDoorB_1->setVisible(false);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightB->setVisible(true);
			}
		}
	}
	else
	{
		if (isMakeDoorR)
		{
			closeDoorR->setVisible(true);
			closeDoorR_1->setVisible(true);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightR->setVisible(false);
			}
		}

		if (isMakeDoorL)
		{
			closeDoorL->setVisible(true);
			closeDoorL_1->setVisible(true);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightL->setVisible(false);
			}
		}

		if (isMakeDoorT)
		{
			closeDoorT->setVisible(true);
			closeDoorT_1->setVisible(true);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightT->setVisible(false);
			}
		}

		if (isMakeDoorB)
		{
			closeDoorB->setVisible(true);
			closeDoorB_1->setVisible(true);

			if (_doorname == BossRoomDoor)
			{
				//BossDoorLightB->setVisible(false);
			}
		
		}
	}
}

void MapBase::SetRoomNumber()
{
	if (mapRect.containsPoint(Player->getIsaacBody()->getPosition()) && !CI->camera->getNumberOfRunningActions())
	{
		Player->setRoomNumber(RoomNumber);
	}
}

void MapBase::ChangeDoorRTag()
{
	doorR->setTag(OpenDoor);
	Player->getDoorOpenKey()->setVisible(false);
	Player->setKeyCount(Player->getKeyCount() - 1);
}

void MapBase::ChangeDoorLTag()
{
	doorL->setTag(OpenDoor);
	Player->getDoorOpenKey()->setVisible(false);
	Player->setKeyCount(Player->getKeyCount() - 1);
}

void MapBase::ChangeDoorTTag()
{
	doorT->setTag(OpenDoor);
	Player->getDoorOpenKey()->setVisible(false);
	Player->setKeyCount(Player->getKeyCount() - 1);
}

void MapBase::ChangeDoorBTag()
{
	doorB->setTag(OpenDoor);
	Player->getDoorOpenKey()->setVisible(false);
	Player->setKeyCount(Player->getKeyCount() - 1);
}

void MapBase::PlayUnlockSound()
{
	SMI->PlayUnLock();
}

void MapBase::ClearOnDidFinishCount()
{
	if (Player->getRoomNumber() == RoomNumber)
	{
		if (clearOnDidFinishCount > 0)
			clearOnDidFinishCount--;
	}
}
