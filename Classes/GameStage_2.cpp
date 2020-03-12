#include "GameStage_2.h"

Scene * GameStage_2::createScene()
{
	auto scene = GameStage_2::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	auto layer = GameStage_2::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	scene->addChild(layer);

	return scene;
}

bool GameStage_2::init()
{
	if (!Scene::init())
		return false;

	CI->CreateCamera(this);

	endingScreenBg = LayerColor::create(Color4B::BLACK);
	endingScreenBg->setOpacity(0);
	this->addChild(endingScreenBg, 100000);

	// 물리효과 구현 범위 //
	auto edgeBody = PhysicsBody::createEdgeBox(Size(DI->getWinSize().width - 100, DI->getWinSize().height - 70), PhysicsMaterial(0, 1, 0), 3);
	edgeBody->setContactTestBitmask(true);
	edgeBody->setCollisionBitmask(10);

	auto node = Node::create();
	node->setPosition(Point(0, 0));
	node->setPhysicsBody(edgeBody);
	CI->camera->addChild(node);

	edgeSegment[0] = PhysicsBody::createEdgeSegment(Vec2(-240, 90), Vec2(-10, 90));
	edgeSegment[1] = PhysicsBody::createEdgeSegment(Vec2(10, 90), Vec2(240, 90));
	edgeSegment[2] = PhysicsBody::createEdgeSegment(Vec2(-240, -90), Vec2(-10, -90));
	edgeSegment[3] = PhysicsBody::createEdgeSegment(Vec2(10, -90), Vec2(240, -90));

	edgeSegment[4] = PhysicsBody::createEdgeSegment(Vec2(-180, 135), Vec2(-180, 10));
	edgeSegment[5] = PhysicsBody::createEdgeSegment(Vec2(-180, -135), Vec2(-180, -10));
	edgeSegment[6] = PhysicsBody::createEdgeSegment(Vec2(180, 135), Vec2(180, 10));
	edgeSegment[7] = PhysicsBody::createEdgeSegment(Vec2(180, -135), Vec2(180, -10));

	isPlayBgm = false;

	for (int i = 0; i < 8; i++)
	{
		edgeSegment[i]->setContactTestBitmask(true);
		edgeSegment[i]->setCollisionBitmask(15);

		edgeNode[i] = Node::create();
		edgeNode[i]->setPosition(Point(0, 0));
		edgeNode[i]->setPhysicsBody(edgeSegment[i]);
		CI->camera->addChild(edgeNode[i]);
	}

	// 맵 제작 //
	MapCase[0] = new MapCase_11(this, Position_50_50_);
	MapCase[1] = new MapCase_12(this, Position_49_50_);
	MapCase[2] = new MapCase_13(this, Position_50_49_);
	MapCase[3] = new MapCase_14(this, Position_51_50_);
	MapCase[4] = new MapCase_15(this, Position_50_48_);
	MapCase[5] = new MapCase_16_ItemRoom2(this, Position_48_50_);
	MapCase[6] = new MapCase_17(this, Position_49_51_);
	MapCase[7] = new MapCase_18(this, Position_51_51_);
	MapCase[8] = new MapCase_19(this, Position_51_52_);
	MapCase[9] = new MapCase_20(this, Position_52_50_);
	MapCase[10] = new MapCase_21(this, Position_52_49_);
	MapCase[11] = new MapCase_22(this, Position_53_50_);
	MapCase[12] = new MapCase_23_BossRoom(this, Position_53_51_);
	MapCase[13] = new MapCase_24_ShopRoom(this, Position_52_48_);
	MapCase[14] = new MapCase_25(this, Position_50_47_);
	MapCase[15] = new MapCase_26(this, Position_49_52_);

	// 미니맵 제작 //
	miniMap = new MiniMap_2(this, MapCase);

	// 스케쥴 관리 //

	// 플레이어를 만든다.
	Player->CreateIsaac(this);

	// 스테이지 번호 설정
	//Player->setStageNumber(2);

	// 키보드를 만든다.
	KCI->CreateKeyListener(this);

	// Physics 충돌 리스너를 만든다.
	KCI->CreateContactListener(this);

	return true;
}

void GameStage_2::tick(float delta)
{
	if (!Player->getPlayerIsDead())
	{
		Player->tick();

		miniMap->tick();

		// 방 tick함수 실행
		/*for (int i = 0; i < 10; i++)
		{
			MapCase[i]->tick();
		}*/

		MapCase[0]->tick();
		MapCase[1]->tick();
		MapCase[2]->tick();
		MapCase[3]->tick();
		MapCase[4]->tick();
		MapCase[5]->tick();
		MapCase[6]->tick();
		MapCase[7]->tick();
		MapCase[8]->tick();
		MapCase[9]->tick();
		MapCase[10]->tick();
		MapCase[11]->tick();
		MapCase[12]->tick();
		MapCase[13]->tick();
		MapCase[14]->tick();
		MapCase[15]->tick();

		// 아이작의 총알 백터
		for (int i = 0; i < Player->isaacBulletVec.size(); i++)
		{
			Player->isaacBulletVec[i]->tick();

			if (Player->isaacBulletVec[i]->bulletShadow->getTag() == EraseOnVec)
			{
				Player->isaacBulletVec.erase(Player->isaacBulletVec.begin() + i);
			}
		}

		// 몬스터의 총알 백터
		for (int i = 0; i < Player->monsterBulletVec.size(); i++)
		{

			Player->monsterBulletVec[i]->tick();

			if (Player->monsterBulletVec[i]->bulletShadow->getTag() == EraseOnVec)
			{
				Player->monsterBulletVec.erase(Player->monsterBulletVec.begin() + i);
			}
		}

		// Bone(뼈) 백터
		for (int i = 0; i < Player->BoneVec.size(); i++)
		{

			Player->BoneVec[i]->tick();

			if (Player->BoneVec[i]->bulletShadow->getTag() == EraseOnVec)
			{
				Player->BoneVec.erase(Player->BoneVec.begin() + i);
			}
		}

		// 오브젝트 백터
		for (int i = 0; i < Player->objectVec.size(); i++)
		{
			Player->objectVec[i]->tick();

			if (Player->objectVec[i]->ObjectSprite->getTag() == ObjectErase)
			{
				Player->objectVec.erase(Player->objectVec.begin() + i);
			}
		}

		// 아이템 백터
		for (int i = 0; i < Player->itemBaseVec.size(); i++)
		{

			Player->itemBaseVec[i]->tick();

			if (Player->itemBaseVec[i]->itemSprite->getTag() == ItemErase)
			{
				Player->itemBaseVec.erase(Player->itemBaseVec.begin() + i);
			}
		}

		// 몬스터 백터
		for (int i = 0; i < Player->monsterVec.size(); i++)
		{
			if (!Player->getIsLoadingScene())
				Player->monsterVec[i]->tick();

			if (Player->monsterVec[i]->monsterSprite->getTag() == MonsterErase)
			{
				Player->monsterVec.erase(Player->monsterVec.begin() + i);
			}
		}
	}

	if (Player->getSceneChange())
	{
		Player->isaacBulletVec.clear();
		Player->monsterBulletVec.clear();
		Player->objectVec.clear();
		Player->itemBaseVec.clear();
		Player->monsterVec.clear();

		// 엔딩 부분 !!
		log("엔딩!");

		endingScreenBg->setPosition(Vec2(CI->camera->getPosition().x - DI->getWinSize().width / 2, CI->camera->getPosition().y - DI->getWinSize().height / 2));
		endingScreenBg->runAction(FadeIn::create(1.f));


		Player->setSceneChange(false);
	}

	// 디버그를 보여줄지에 대한 여부
	DCI->ShowDebug(sceneWorld);
}

void GameStage_2::onEnterTransitionDidFinish()
{
	// BGM 재생 [처음 씬이 전환됬을때만 실행된다.]
	if (!isPlayBgm)
	{
		SMI->PlayTheCave();
		isPlayBgm = true;
	}

	Player->setStageNumber(2);
	this->schedule(schedule_selector(GameStage_2::tick));
}