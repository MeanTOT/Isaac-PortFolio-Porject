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

	mapCase_1 = new MapCase_1(this, Position_50_50_);
	mapCase_2 = new MapCase_2(this, Position_50_49_);
	mapCase_3 = new MapCase_3(this, Position_51_50_);
	mapCase_4 = new MapCase_4(this, Position_49_50_);
	mapCase_5 = new MapCase_5(this, Position_50_51_);


	// 스케쥴 관리 //
	this->schedule(schedule_selector(GameStage_1::tick));


	Player->CreateIsaac(this);
	KCI->CreateKeyListener(this);
	KCI->CreateContactListener(this);

	return true;
}

void GameStage_1::tick(float delta)
{
	Player->tick();
	mapCase_1->tick();
	mapCase_2->tick();
	mapCase_3->tick();
	mapCase_4->tick();
	mapCase_5->tick();

	for (int i = 0; i < Player->isaacBulletVec.size(); i++)
	{
		Player->isaacBulletVec[i]->tick();

		if (Player->isaacBulletVec[i]->bulletShadow->getTag() == EraseOnVec)
		{
			//delete[] Player->isaacBulletVec[i];
			Player->isaacBulletVec.erase(Player->isaacBulletVec.begin() + i);
		}
	}

	for (int i = 0; i < Player->objectVec.size(); i++)
	{
		Player->objectVec[i]->tick();

		if (Player->objectVec[i]->ObjectSprite->getTag() == ObjectErase)
		{
			Player->objectVec.erase(Player->objectVec.begin() + i);
		}
	}

	DCI->ShowDebug(sceneWorld);

}

void GameStage_1::onEnterTransitionDidFinish()
{
	SMI->PlaydipteraSonata();
}
