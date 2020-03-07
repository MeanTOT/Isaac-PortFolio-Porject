#include "GameStage_1.h"

Scene * GameStage_1::createScene()
{
	auto scene = GameStage_1::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL); // 범위를 보여준다.
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	auto layer = GameStage_1::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	
	scene->addChild(layer);

	return scene;
}

bool GameStage_1::init()
{
	if (!Scene::init())
		return false;
	
	CI->CreateCamera(this);

	// 물리효과 구현 범위 //
	auto edgeBody = PhysicsBody::createEdgeBox(Size(DI->getWinSize().width - 100, DI->getWinSize().height - 70), PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setContactTestBitmask(true);
	edgeBody->setCollisionBitmask(10);
	
	auto node = Node::create();
	node->setPosition(Point(0,0));
	node->setPhysicsBody(edgeBody);
	CI->camera->addChild(node);

	edgeSegment[0] = PhysicsBody::createEdgeSegment(Vec2(-240, 90), Vec2(-10,90));
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
		edgeNode[i]->setPosition(Point(0,0));
		edgeNode[i]->setPhysicsBody(edgeSegment[i]);
		CI->camera->addChild(edgeNode[i]);
	}

	// 맵 제작 //
	MapCase[0] = new MapCase_1(this, Position_50_50_);
	MapCase[1] = new MapCase_2(this, Position_50_51_);
	MapCase[2] = new MapCase_3(this, Position_49_50_);
	MapCase[3] = new MapCase_4(this, Position_50_49_);
	MapCase[4] = new MapCase_5(this, Position_51_49_);
	MapCase[5] = new MapCase_6(this, Position_50_48_);
	MapCase[6] = new MapCase_7(this, Position_49_47_);
	MapCase[7] = new MapCase_8(this, Position_50_47_);
	MapCase[8] = new MapCase_ItemRoom1(this, Position_50_46_);
	MapCase[9] = new MapCase_BossRoom(this, Position_52_49_);

	// 미니맵 제작 //
	miniMap = new MiniMap(this, MapCase);

	// 스케쥴 관리 //
	this->schedule(schedule_selector(GameStage_1::tick));

	// 플레이어를 만든다.
	Player->CreateIsaac(this);

	// 스테이지 번호 설정
	Player->setStageNumber(1);

	// 키보드를 만든다.
	KCI->CreateKeyListener(this);

	// Physics 충돌 리스너를 만든다.
	KCI->CreateContactListener(this);

	return true;
}

void GameStage_1::tick(float delta)
{
	if (!Player->getPlayerIsDead())
	{
		Player->tick();

		miniMap->tick();

		// 방 tick함수 실행
		for (int i = 0; i < 10; i++)
		{
			MapCase[i]->tick();
		}

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

		AudioEngine::stopAll();
		auto pScene = LoadingScreen2::createScene();
		DI->replaceScene(TransitionFade::create(1.0f, pScene));
		Player->setSceneChange(false);
	}

	// 디버그를 보여줄지에 대한 여부
	DCI->ShowDebug(sceneWorld);

}

void GameStage_1::onEnterTransitionDidFinish()
{
	// BGM 재생 [처음 씬이 전환됬을때만 실행된다.]
	if (!isPlayBgm)
	{
		SMI->PlaydipteraSonata();
		isPlayBgm = true;
	}
}
