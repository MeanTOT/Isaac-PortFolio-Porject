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

	// ����ȿ�� ���� ���� //
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

	// �� ���� //
	MapCase[0] = new MapCase_11(this, Position_50_50_);
	MapCase[1] = new MapCase_12(this, Position_49_50_);
	MapCase[2] = new MapCase_13(this, Position_50_49_);
	MapCase[3] = new MapCase_14(this, Position_51_50_);
	MapCase[4] = new MapCase_15(this, Position_50_48_);
	//MapCase[5] = new MapCase_6(this, Position_50_48_);
	//MapCase[6] = new MapCase_7(this, Position_49_47_);
	//MapCase[7] = new MapCase_8(this, Position_50_47_);
	//MapCase[8] = new MapCase_ItemRoom1(this, Position_50_46_);
	//MapCase[9] = new MapCase_BossRoom(this, Position_52_49_);

	// �̴ϸ� ���� //
	miniMap = new MiniMap(this, MapCase);

	// ������ ���� //

	// �÷��̾ �����.
	Player->CreateIsaac(this);

	// �������� ��ȣ ����
	//Player->setStageNumber(2);

	// Ű���带 �����.
	KCI->CreateKeyListener(this);

	// Physics �浹 �����ʸ� �����.
	KCI->CreateContactListener(this);

	return true;
}

void GameStage_2::tick(float delta)
{
	if (!Player->getPlayerIsDead())
	{
		Player->tick();

		miniMap->tick();

		// �� tick�Լ� ����
		/*for (int i = 0; i < 10; i++)
		{
			MapCase[i]->tick();
		}*/

		MapCase[0]->tick();
		MapCase[1]->tick();
		MapCase[2]->tick();
		MapCase[3]->tick();
		MapCase[4]->tick();

		// �������� �Ѿ� ����
		for (int i = 0; i < Player->isaacBulletVec.size(); i++)
		{
			Player->isaacBulletVec[i]->tick();

			if (Player->isaacBulletVec[i]->bulletShadow->getTag() == EraseOnVec)
			{
				Player->isaacBulletVec.erase(Player->isaacBulletVec.begin() + i);
			}
		}

		// ������ �Ѿ� ����
		for (int i = 0; i < Player->monsterBulletVec.size(); i++)
		{

			Player->monsterBulletVec[i]->tick();

			if (Player->monsterBulletVec[i]->bulletShadow->getTag() == EraseOnVec)
			{
				Player->monsterBulletVec.erase(Player->monsterBulletVec.begin() + i);
			}
		}

		// ������Ʈ ����
		for (int i = 0; i < Player->objectVec.size(); i++)
		{
			Player->objectVec[i]->tick();

			if (Player->objectVec[i]->ObjectSprite->getTag() == ObjectErase)
			{
				Player->objectVec.erase(Player->objectVec.begin() + i);
			}
		}

		// ������ ����
		for (int i = 0; i < Player->itemBaseVec.size(); i++)
		{

			Player->itemBaseVec[i]->tick();

			if (Player->itemBaseVec[i]->itemSprite->getTag() == ItemErase)
			{
				Player->itemBaseVec.erase(Player->itemBaseVec.begin() + i);
			}
		}

		// ���� ����
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

	// ����׸� ���������� ���� ����
	DCI->ShowDebug(sceneWorld);
}

void GameStage_2::onEnterTransitionDidFinish()
{
	// BGM ��� [ó�� ���� ��ȯ�������� ����ȴ�.]
	if (!isPlayBgm)
	{
		SMI->PlaydipteraSonata();
		isPlayBgm = true;
	}

	Player->setStageNumber(2);
	this->schedule(schedule_selector(GameStage_2::tick));
}